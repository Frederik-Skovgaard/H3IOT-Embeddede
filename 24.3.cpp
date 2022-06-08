#include <Arduino.h>


void setup()
{
	Serial.begin(9600); 
	
	Serial.print("A");
}

void loop()
{
	Serial.print("A");
	delay(1000);
}

