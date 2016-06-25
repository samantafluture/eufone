// initialize variables
int lightSensorValue = 0; 
int lightSensorPin = A4; 
int LEDpin = 13;
int threshold = 150;

void setup() {
  // initialize serial communication:
  Serial.begin(4800);
  pinMode(LEDpin,OUTPUT);
 // pinMode(A3,OUTPUT); 
 // digitalWrite(A3,HIGH); // set A3 as vcc
}

void loop() {
  // read the value from the sensor 
  lightSensorValue = analogRead(lightSensorPin);

  // if the ambient light is bright
  if(lightSensorValue>threshold){ 
    //print mode
    Serial.print("Cor");
    // Blink LED
	digitalWrite(LEDpin, HIGH);  
  	delay(150);              
  	digitalWrite(LEDpin, LOW);    
  	delay(150);               
  }

  // if the ambient light is dark
  else{
    // print mode
    Serial.println("Escurecer"); 
    // Fade LED
  	analogWrite(LEDpin, 255); 
  	delay(300);
  	analogWrite(LEDpin, 200); 
  	delay(300);
  	analogWrite(LEDpin, 150);
  	delay(300);
  	analogWrite(LEDpin, 100);
  	delay(300);
  	analogWrite(LEDpin, 50); 
  	delay(300); 
  	analogWrite(LEDpin, 0); 
  	delay(600);
  }

  Serial.print(" Sensor Value: ");
  Serial.println(lightSensorValue);

  // delay between readings: 
  delay(1000); 
}
