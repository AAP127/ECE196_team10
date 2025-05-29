#define ECHOPIN 3// Pin to receive echo pulse
#define TRIGPIN 2// Pin to send trigger pulse

//This simple demonstration uses a simple threshold value for detection
#define THRESHOLD 40

// Spot type: A-1, B-2, S-3, V-4
#define SPOT_TYPE 2



void setup(){
  Serial.begin(9600);
  pinMode(ECHOPIN, INPUT);
  pinMode(TRIGPIN, OUTPUT);
  digitalWrite(ECHOPIN, HIGH);
}
void loop(){
  digitalWrite(TRIGPIN, LOW); // Set the trigger pin to low for 2uS
  delayMicroseconds(2);
  digitalWrite(TRIGPIN, HIGH); // Send a 10uS high to trigger ranging
  delayMicroseconds(10);
  digitalWrite(TRIGPIN, LOW); // Send pin low again
  int distance = pulseIn(ECHOPIN, HIGH,26000); // Read in times pulse
  // Serial.print("Raw distance reported: ");
  // Serial.println(distance);

  distance= distance/58;

   
  Serial.print("Spot type: ");
  Serial.print(SPOT_TYPE);
  Serial.print(", ");

  Serial.print(distance);
  Serial.print(" cm: ");

 


  //Determine if sensor detects a car, sensor reads 0 when it doesn't recieve a return
  if(distance <= THRESHOLD){
    Serial.println("OCCUPIED");
  }
  else{
    Serial.println("EMPTY");
  }



  delay(50);// Wait 50mS before next ranging
}