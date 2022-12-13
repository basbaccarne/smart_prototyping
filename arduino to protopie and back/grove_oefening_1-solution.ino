/*
  Two-way communication between an Arduino and Protopie
  This script shows how to interact between Protopie and Arduino using Serial Communication
  The hardware entails:
    * A Grove-Red LED connected to port D2 of a Grove-Base Shield
    * A Grove Grove-Rotary Angle Sensor(P) to port A0 of a Grove-Base Shield

  modified December 13 2022
  by Bas Baccarne
*/

// define variables
int oldSensorValue;
String oldScreenbuttonState = "led_off";
String newScreenbuttonState ="led_off";

// define pin numbers of led (D2) and rotary angle sensor (A0)
#define ledPin 2
#define rotarySensor A0

void setup() {
  // open serial communication
  Serial.begin(9600);

  // define input and output
  pinMode(rotarySensor, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // DIRECTION 1: ARDUINO TO PROTOPIE (send the value of the rotary angle sensor)
  
  // read rotary sensor state
  int sensorValue = analogRead(rotarySensor);

  // if the rotaty angle sensor changes, send the new value
  // we only send data when something changes to be as sparse as possible on the transactions
  if (oldSensorValue != sensorValue){
    // reset the change detection variable
    oldSensorValue = sensorValue;
    // send the angle value (0 to 1023 as variable "angle")
    Serial.print("angle||");
    Serial.println(sensorValue);
  } 

  // DIRECTION 2: PROTOPIE 2 ARDUINO (check for "led" message and turn led on if detected)

  // if information is coming in through the serial
  if(Serial.available()){
      // read it until the semicolon
      newScreenbuttonState = Serial.readStringUntil(';');
  }

  if(newScreenbuttonState == "led_on"){
    digitalWrite(ledPin, HIGH);
    oldScreenbuttonState = newScreenbuttonState;
  }

    if(newScreenbuttonState == "led_off"){
    digitalWrite(ledPin, LOW);
    oldScreenbuttonState = newScreenbuttonState;
  }

}
