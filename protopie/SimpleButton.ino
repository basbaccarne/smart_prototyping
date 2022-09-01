// wiring:
// 3.3V <--> button side 1
// button side 2 <--> digital pin 2
// button side 2 <--> 10k ohm resistor <--> ground

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
  int buttonState = digitalRead(buttonPin);
  Serial.println(buttonState);
  delay(1); 
}
