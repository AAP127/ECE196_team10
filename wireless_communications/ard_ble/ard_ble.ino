/*
  Code has been adapted from the below tutorial:


  Rui Santos & Sara Santos - Random Nerd Tutorials
  Complete project details at https://RandomNerdTutorials.com/esp32-web-bluetooth/
  Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files.
  The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
*/

#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>

#define TRIGPIN 35// Pin to send trigger pulse
#define ECHOPIN 36// Pin to receive echo pulse


BLEServer* pServer = NULL;
BLECharacteristic* pSensorCharacteristic = NULL;
bool deviceConnected = false;
bool oldDeviceConnected = false;
uint32_t value = 0;


//Device Setup parameters
// See the following for generating UUIDs: https://www.uuidgenerator.net/

/*
  When assigning additional sensors, the following needs to be done:

  - Change the DEVICE_NUM (used for naming and device reports)
  - Add a new UUID
  - Update the parking mode indicated
  - Ensure the server side also is updated to accomodate the additional sensor (UUID, physical display, etc)

*/
#define SERVICE_UUID        "19b10000-e8f2-537e-4f6c-d104768a1214"

//Uncomment for Sensor0
// #define SENSOR_CHARACTERISTIC_UUID "19b10001-e8f2-537e-4f6c-d104768a1214"
// #define DEVICE_NUM    "0"
// String device_mode = "S";

//Uncomment for Sensor1
#define SENSOR_CHARACTERISTIC_UUID "19b10002-e8f2-537e-4f6c-d104768a1214"
#define DEVICE_NUM    "1"
String device_mode = "A";




class MyServerCallbacks: public BLEServerCallbacks {
  void onConnect(BLEServer* pServer) {
    deviceConnected = true;
  };

  void onDisconnect(BLEServer* pServer) {
    deviceConnected = false;
  }
};



void setup() {
  Serial.begin(115200);

  //Sample sensor code setup
  pinMode(ECHOPIN, INPUT);
  pinMode(TRIGPIN, OUTPUT);




  // Create the BLE Device
  String device_id = String("ESP32-Sensor") + String(DEVICE_NUM);
  BLEDevice::init(device_id);


  // Create the BLE Server
  pServer = BLEDevice::createServer();
  pServer->setCallbacks(new MyServerCallbacks());

  // Create the BLE Service
  BLEService *pService = pServer->createService(SERVICE_UUID);

  // Create a BLE Characteristic
  pSensorCharacteristic = pService->createCharacteristic(
                      SENSOR_CHARACTERISTIC_UUID,
                      BLECharacteristic::PROPERTY_READ   |
                      BLECharacteristic::PROPERTY_WRITE  |
                      BLECharacteristic::PROPERTY_NOTIFY |
                      BLECharacteristic::PROPERTY_INDICATE
                    );

  // https://www.bluetooth.com/specifications/gatt/viewer?attributeXmlFile=org.bluetooth.descriptor.gatt.client_characteristic_configuration.xml
  // Create a BLE Descriptor
  pSensorCharacteristic->addDescriptor(new BLE2902());

  // Start the service
  pService->start();

  // Start advertising
  BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
  pAdvertising->addServiceUUID(SERVICE_UUID);
  pAdvertising->setScanResponse(false);
  pAdvertising->setMinPreferred(0x0);  // set value to 0x00 to not advertise this parameter
  BLEDevice::startAdvertising();
  Serial.println("Waiting a client connection to notify...");
}




void loop() {
  //Sample sensor polling code and occupancy detection
  digitalWrite(TRIGPIN, LOW); // Set the trigger pin to low for 2uS
  delayMicroseconds(2);
  digitalWrite(TRIGPIN, HIGH); // Send a 10uS high to trigger ranging
  delayMicroseconds(10);
  digitalWrite(TRIGPIN, LOW); // Send pin low again
  int distance = pulseIn(ECHOPIN, HIGH,26000); // Read in times pulse
  distance= distance/58;
  Serial.print(distance);
  Serial.println(" cm");
  delay(50);// Wait 50mS before next ranging

  //Example threshold detection, replace this with alogrithm to average detections across both sensors
  int available = 0;
  if (distance > 30){
    available = 1;
  }


  //Temporary overwrite of dist and avail for testing (since sensor isn't conencted to esp)
  distance = value;
  if(distance %2 == 0){
    available = 0;
  }


  // notify changed value
  if (deviceConnected) {
    //Device reports in format: ID, Type, Occupancy status, Distance
    //Depending on how multi device support is implemented, having ID could be redundant
    //If using float or double for distance, need to consider type conversions: Length and potential type conversion issues
    String device_report = String(DEVICE_NUM)+"," +device_mode +"," + String(available) +"," + String(distance);

    pSensorCharacteristic->setValue(String(device_report).c_str());
    // pSensorCharacteristic->setValue(String(value).c_str());
    pSensorCharacteristic->notify();
    value++;
    Serial.print("New value notified: ");
    Serial.println(value);
    delay(3000); // bluetooth stack will go into congestion, if too many packets are sent, in 6 hours test i was able to go as low as 3ms
  }
  // disconnecting
  if (!deviceConnected && oldDeviceConnected) {
    Serial.println("Device disconnected.");
    delay(500); // give the bluetooth stack the chance to get things ready
    pServer->startAdvertising(); // restart advertising
    Serial.println("Start advertising");
    oldDeviceConnected = deviceConnected;
  }
  // connecting
  if (deviceConnected && !oldDeviceConnected) {
    // do stuff here on connecting
    oldDeviceConnected = deviceConnected;
    Serial.println("Device Connected");
  }
}