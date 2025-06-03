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
#include <NewPing.h>


#define upper_limit_inCM  130

#define Trig1  33  // Sensor 1 Trigger
#define Echo1  47   // Sensor 1 Echo

#define Trig2  21   // Sensor 2 Trigger
#define Echo2  26 // Sensor 2 Echo


#define LED_Occupied    36
#define LED_Available   35

#define Max_distance 400
#define Threshold_inCM 50  
#define Sample_duration 1000
#define Sample_interval 50

NewPing sonar1(Trig1, Echo1, Max_distance);
NewPing sonar2(Trig2, Echo2, Max_distance);


//Sensor state set up
bool sensor1_detect = false;
bool sensor2_detect = false;


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




//LED indicator sensor pins
// #define LED   37     //A
//#define LED 38      //B
#define LED   48     //S
//#define LED 34     //V



//Uncomment for Sensor0
 #define SENSOR_CHARACTERISTIC_UUID "19b10001-e8f2-537e-4f6c-d104768a1214"
 #define DEVICE_NUM    "0"
 String device_mode = "S";

//Uncomment for Sensor1
//#define SENSOR_CHARACTERISTIC_UUID "19b10002-e8f2-537e-4f6c-d104768a1214"
//#define DEVICE_NUM    "1"
//String device_mode = "A";




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


  //initialize LED pins as outputs
  //  pinMode(LEDA, OUTPUT);
 // pinMode(LEDB, OUTPUT);
  pinMode(LED, OUTPUT);
  //pinMode(LEDV, OUTPUT);
  pinMode(LED_Occupied, OUTPUT);
  pinMode(LED_Available, OUTPUT);

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
 

  digitalWrite(LED, HIGH);

  //cases for led modes
  //how can we make cases : idea , we want led to light up depending on what sensor youre looking at
   // determine what led turns on
  



  unsigned long startTime = millis();
  int count1 = 0, count2 = 0;
  int sum1 = 0, sum2 = 0;

  while (millis() - startTime < Sample_duration) {
    int distance1 = sonar1.ping_cm();
    int distance2 = sonar2.ping_cm();

    if (distance1 > 0) {
      sum1 += distance1;
      count1++;
    }

    if (distance2 > 0) {
      sum2 += distance2;
      count2++;
    }

    delay(Sample_interval);
  }

  float avgDistance1 = -1;
  float avgDistance2 = -1;
  

 //take averages of sensor distances collected over duration of sample size

 if (count1 > 0) {
  avgDistance1 = (float)sum1 / count1;
  }

 if (count2 > 0) {
  avgDistance2 = (float)sum2 / count2;
 }

// sets boolean state to detecting to true if average distance is greater than zero and average distance is less than the threshold

 sensor1_detect = (avgDistance1 > 0 &&avgDistance1 < Threshold_inCM);
 sensor2_detect = (avgDistance2 > 0 &&avgDistance2 < Threshold_inCM);  

  
//now, we need to determine what mode the device is in (what spot its in), create a state for each mode?
 Serial.println(avgDistance1);   Serial.print(" cm");

 Serial.println(avgDistance2);   Serial.print(" cm");
  bool available;     // initialize availability to be passed to website
  int distance = 0;  // initialize distance to be passed to website

Serial.println("=== Vehicle Detection Status ===");


  if (sensor1_detect && !sensor2_detect) {
    Serial.println("Using Sensor 1");
    Serial.print("Avg Distance: "); Serial.print(avgDistance1); Serial.println(" cm");
    Serial.println("Vehicle detected by Sensor 1");
    available = true; 
    distance = avgDistance1;

   // digitalWrite(LED_Occupied, High);
    //digitalWrite(LED_Available,Low);

  } else if (!sensor1_detect && sensor2_detect) {
    Serial.println("Using Sensor 2");
    Serial.print("Avg Distance: "); Serial.print(avgDistance2); Serial.println(" cm");
    Serial.println("Vehicle detected by Sensor 2");
    available = true;
    distance = avgDistance2;
    //digitalrite(LED_Occupied, High);
    //digitalWrite(LED_Available,Low);

  } else if (sensor1_detect && sensor2_detect) {
    Serial.println("Both sensors detect vehicle. Prioritizing Sensor 1.");
    Serial.print("Avg Distance (Sensor 1): "); Serial.print(avgDistance1); Serial.println(" cm");
    Serial.println("Vehicle detected by Sensor 1");
    available = true;
    distance  = avgDistance1;  // can change but if both sensors are detecting a vehicle, prioritize sensor 1
    //digitalWrite(LED_Occupied, HIGH);
    //digitalWrite(LED_Available,Low);

  } else {  // this else statement will be true if both senors aren't detecting a vehicle
    Serial.println("No vehicle detected by either sensor.");
    available = false;
    distance = 0;
   // digitalWrite(LED_Available, HIGH);
    //digitalWrite(LED_Occupied, LOW);
  }

  Serial.println("===============================\n");
  
  // Available as written above is true when the spot is occupied
  //Server expects true when spot is free, so flip before sending
  available = !available;



  if(sensor1_detect || sensor2_detect){
    digitalWrite(LED_Available, LOW);
    digitalWrite(LED_Occupied, HIGH);
    
  }
 

  if(!sensor1_detect && !sensor2_detect) {
    digitalWrite(LED_Occupied, LOW);
    digitalWrite(LED_Available, HIGH);

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
