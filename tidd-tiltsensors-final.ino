// constants won't change. They're used here to 
// set pin numbers:
const int tiltPin = 11;     // the number of the tilt pin
const int LEDpin =  13;      // the number of the LED pin

// variables will change:
int tiltState = 0;         // variable for reading the tilt status

void setup() {
  // initialize serial communication:
  Serial.begin(4800);
  // initialize the LED pin as an output:
  pinMode(LEDpin, OUTPUT);
  // initialize the tilt1 pin as an input:
  pinMode(tiltPin, INPUT);
  pinMode(11, INPUT_PULLUP);
  // set a0 as ground 
 // pinMode(A0,OUTPUT); 
  // digitalWrite(A0,LOW); 
}

void loop(){
  // read the state of the tilt1 value:
  tiltState = digitalRead(tiltPin);
  
  // check if the tilt1 is up
  // if it is, the tiltState1 is HIGH:
  if (tiltState == HIGH) {     
    // print mode
    Serial.print("Hold"); 
    // turn LED on:    
    digitalWrite(LEDpin, HIGH);
  } 
  else {
    // print mode
    Serial.print("Flip");  
    // turn LED off:
    digitalWrite(LEDpin, LOW); 
  }
  
  // delay between readings: 
  delay(1000); 
}
