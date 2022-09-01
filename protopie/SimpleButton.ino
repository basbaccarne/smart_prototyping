// wiring:
// 3.3V <--> button side 1
// button side 2 <--> digital pin 2
// button side 2 <--> 10k ohm resistor <--> ground

// variables
int oldButtonState = LOW;

// pin numbers
int buttonPin = 2;

// setup
void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
  
}

// loop
void loop() {
  // read button
  int newButtonState = digitalRead(buttonPin);

  // check for changes
  if(newButtonState != oldButtonState){
     Serial.println(newButtonState);
     oldButtonState = newButtonState;
  }
  
  delay(1); 
}
