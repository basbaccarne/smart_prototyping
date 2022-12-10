/*
  Two-way communication between an Arduino and Protopie
  This script shows how to interact between Protopie and Arduino using Serial Communication
  The hardware entails:
    * A Grove-Red LED connected to port D2 of a Grove-Base Shield
    * A Grove Grove-Button to port D4 of a Grove-Base Shield

  modified December 10th 2022
  by Bas Baccarne
*/

// define variables
int oldButtonState = LOW;
String oldScreenbuttonState = "led_off";
String newScreenbuttonState ="led_off";

// define pin numbers of led (D2) and button (D4)
const int ledPin = 2;
const int buttonPin = 4;

void setup() {
  // open serial communication
  Serial.begin(9600);

  // define input and output
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // DIRECTION 1: ARDUINO TO PROTOPIE (send a message when the button is pressed)
  
  // read button state
  int newButtonState = digitalRead(buttonPin);

  // when the button is pressed (1) OR released (0), send the value over serial using the variable "button"
  if (newButtonState != oldButtonState) {
      Serial.print("button||");
      Serial.println(newButtonState);
      oldButtonState = newButtonState;
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
