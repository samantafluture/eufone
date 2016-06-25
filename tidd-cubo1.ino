#include <CapacitiveSensor.h>

// light sensor
int lightSensorValue = 0; // light sensor value
int threshold = 50;
int lightSensorPin = A4; // set A4 as pin sensor
int LEDpin1 = 9; // set pin 9 as led

// tilt sensor
int tiltState = 0; // tilt sensor state
int tiltPin = 13; // set 13 as pin sensor
int LEDpin2 =  10; // set pin 10 as led   

// capacitive sensor
CapacitiveSensor   cs_A1_A2 = CapacitiveSensor(A1,A2);  // set A1 send pin and A2 as receive pin
int LEDpin3 = 11; // set pin 11 as led 

void setup() {
  
  // initialize serial communication
  Serial.begin(4800);
  
  // set LED pins as outputs
  pinMode(LEDpin1,OUTPUT);
  pinMode(LEDpin2,OUTPUT);
  pinMode(LEDpin3,OUTPUT);
  
  // set A3 as vcc for light sensor
  pinMode(A3,OUTPUT); 
  digitalWrite(A3,HIGH); 
  
  // use interior resistor for pin tilt
  pinMode(tiltPin, INPUT);
  pinMode(13, INPUT_PULLUP);
  
  // set A0 as ground for tilt sensor
  pinMode(A0,OUTPUT); 
  digitalWrite(A0,LOW);
}

void loop() {
  
//----- light sensor -----
  
  // read the value from the sensor 
  lightSensorValue = analogRead(lightSensorPin); 
  Serial.print("\t"); 
  //Serial.print(" Sensor Value: ");
  //Serial.println(lightSensorValue); 
  
  // if the ambient light is bright, blink the led
  if(lightSensorValue>threshold){ 
    Serial.print("Color");
	digitalWrite(LEDpin1, HIGH);  
  	delay(150);              
  	digitalWrite(LEDpin1, LOW);    
  	delay(150);               
  }
  
  // if the ambient light is dark, fade the led
  else{
    Serial.println("Dark"); 
  	analogWrite(LEDpin1, 255); 
  	delay(300);
  	analogWrite(LEDpin1, 200); 
  	delay(300);
  	analogWrite(LEDpin1, 150);
  	delay(300);
  	analogWrite(LEDpin1, 100);
  	delay(300);
  	analogWrite(LEDpin1, 50); 
  	delay(300); 
  	analogWrite(LEDpin1, 0); 
  	delay(600);
  }

  //----- tilt sensor -----
  
  // read the value from the sensor 
  tiltState = digitalRead(tiltPin);
  Serial.print("\t"); 
  
  // if the tilt is up: tiltState is HIGH and turn the led on
  if (tiltState == HIGH) {     
    Serial.print("Flip"); 
    digitalWrite(LEDpin2, HIGH);
  } 
  else {
    Serial.print("Hold");  
    digitalWrite(LEDpin2, LOW); 
  }
  
  //----- capacitive sensor -----
  
  // check on performance in milliseconds, tab character and print value
  long start = millis();
  long total1 =  cs_A1_A2.capacitiveSensor(30);
    //Serial.print(millis() - start);  
    Serial.print("\t");                    
    //Serial.println(total1);       
    
  // if touched
  if(total1>50 && total1<100){ 
    Serial.print("Vibrate"); 
        // turn led on
	digitalWrite(LEDpin3, HIGH);               
  }
  else{
    Serial.print("Still");
        // turn led off
       digitalWrite(LEDpin3, LOW);
  }
  
  
  // delay between readings: 
  delay(1000); 
}
