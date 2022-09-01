// wiring:
// 3.3V <--> button side 1
// button side 2 <--> digital pin 2
// button side 2 <--> 10k ohm resistor <--> ground

// variables
int oldButtonState = LOW;
char oldScreenbuttonState = 'o';

// pin numbers
int buttonPin = 2;

// setup
void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  
}

// loop
void loop() {
  // ARDUINO 2 PROTOPIE - read button state and send changes through a serial message
  int newButtonState = digitalRead(buttonPin);
  
  if(newButtonState != oldButtonState){
     Serial.println(newButtonState);
     oldButtonState = newButtonState;
  }

  // PROTOPIE 2 ARUINO - check for led message and turn internal led on if detected
  char newScreenbuttonState = Serial.read();

  if(newScreenbuttonState == 'i'){
    digitalWrite(LED_BUILTIN, HIGH);
    oldScreenbuttonState = newScreenbuttonState;
  }

    if(newScreenbuttonState == 'o'){
    digitalWrite(LED_BUILTIN, LOW);
    oldScreenbuttonState = newScreenbuttonState;
  }

  // delay
  delay(1); 
}
