/*1. EchoString.cpp */

// Demo af Serial.available() Serial.print() og Serial.println(). Benyt Terminal Window uden LF og CR

#include <Arduino.h>

int incomingByte = 0; // for incoming serial data

void setup()
{
	Serial.begin(115200);		// opens serial port, sets data rate to 9600 bps
	while(!Serial);				// used on SAMD boards
	Serial.println("Serial 9600 baud!");
}

void loop()
{
	// reply only when you receive data:
	if (Serial.available() > 0)
	{
		// read the incoming byte from Buffer:
		incomingByte = Serial.read();

		// say what you got:
		Serial.print("I received: ");
		Serial.print((char)incomingByte);
		Serial.print(" = ");
		Serial.println(incomingByte, HEX);
	}
}