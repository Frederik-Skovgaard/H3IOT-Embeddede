#include <Arduino.h>
#include <SPI.h>



void setup(void) {
	SPI.beginTransaction(SPISettings(4000000, MSBFIRST, SPI_MODE1));
	SPI.begin();
}


void loop(void) {
	
	digitalWrite(SS, LOW);
	
	SPI.transfer ('A');
	SPI.transfer ('B');
	SPI.transfer ('C');
	
	digitalWrite(SS, HIGH);				
	delay(2000);
}