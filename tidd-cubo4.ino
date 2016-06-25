#include <CapacitiveSensor.h>

// light sensor
int lightSensorValue = 0; // light sensor value
int threshold = 50;
int lightSensorPin = A4; // set A4 as pin sensor

// tilt sensor
int tiltState = 0; // tilt sensor state
int tiltPin = 13; // set 13 as pin sensor

// capacitive sensor
CapacitiveSensor   cs_A1_A2 = CapacitiveSensor(A1,A2);  // set A1 send pin and A2 as receive pin

// led
int LEDpin = 9; // set pin 9 as led 

void setup() {
  
  // initialize serial communication
  Serial.begin(4800);
  
  // set LED pins as outputs
  pinMode(LEDpin,OUTPUT);
  
  // use interior resistor for pin tilt
  pinMode(tiltPin, INPUT);
  pinMode(13, INPUT_PULLUP);
  
}

void loop() {
  
//----- light sensor -----
  
  // read the value from the sensor 
  lightSensorValue = analogRead(lightSensorPin); 
  Serial.print("\t"); 
  //Serial.print(" Sensor Value: ");
  //Serial.println(lightSensorValue); 
  
  // if the ambient light is bright, led off
  if(lightSensorValue>threshold){ 
    Serial.print("Color");
	digitalWrite(LEDpin, HIGH);             
  }
  
  // if the ambient light is dark, led on
  else{
    Serial.println("No color"); 
    digitalWrite(LEDpin, LOW); 

  	
  }

  //----- tilt sensor -----
  
  // read the value from the sensor 
  tiltState = digitalRead(tiltPin);
  Serial.print("\t"); 
  
  // if the tilt is up: tiltState is HIGH and turn the led on
  if (tiltState == HIGH) {     
    Serial.print("Flip"); 
    digitalWrite(LEDpin, HIGH);
  } 
  else {
    Serial.print("Hold");  
    digitalWrite(LEDpin, LOW); 
  }
  
  //----- capacitive sensor -----
  
  // check on performance in milliseconds, tab character and print value
  long start = millis();
  long total1 =  cs_A1_A2.capacitiveSensor(30);
    //Serial.print(millis() - start);  
    Serial.print("\t");                    
    //Serial.println(total1);       
    
  // if touched
  if(total1>300 && total1<5000){ 
    Serial.print("Vibrate"); 
        // turn led on         
	digitalWrite(LEDpin, HIGH);               
  }
  else{
    Serial.print("Still");
        // turn led off
       digitalWrite(LEDpin, LOW);
  }
  
  
  // delay between readings: 
  delay(100); 
}
