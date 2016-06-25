#include <CapacitiveSensor.h>

/*
 * CapitiveSense Library Demo Sketch
 * Paul Badger 2008
 * Uses a high value resistor e.g. 10M between send pin and receive pin
 * Resistor effects sensitivity, experiment with values, 50K - 50M. Larger resistor values yield larger sensor values.
 * Receive pin is the sensor pin - try different amounts of foil/metal on this pin
 */

int LEDpin = 13;

CapacitiveSensor   cs_A1_A2 = CapacitiveSensor(A1,A2);        // 10M resistor between pins 4 & 2, pin 2 is sensor pin, add a wire and or foil if desired

void setup()                    
{
   Serial.begin(4800);
   pinMode(LEDpin,OUTPUT);
}

void loop()                    
{
    long start = millis();
    long total1 =  cs_A1_A2.capacitiveSensor(30);

    Serial.print(millis() - start);        // check on performance in milliseconds
    Serial.print("\t");                    // tab character for debug windown spacing

    Serial.println(total1);                  // print sensor output 1

    delay(100);                             // arbitrary delay to limit data to serial port 
    
   
  // if touched
  if(total1>500 && total1<2000){ 
    // LED on
	digitalWrite(LEDpin, HIGH);               
  }

  else{
    //  LED off
	digitalWrite(LEDpin, LOW);
  }
  
    
}
