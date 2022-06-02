#include <Arduino.h>

const int ledPin = 6;

void setup() {
	pinMode(ledPin, OUTPUT);
}

void loop() {
	
	analogWrite(ledPin, 0);
	delay(500);
	analogWrite(ledPin, 32);
	delay(500);
	analogWrite(ledPin, 64);
	delay(500);
	analogWrite(ledPin, 96);
	delay(500);
	analogWrite(ledPin, 128);
	delay(500);
	analogWrite(ledPin, 160);
	delay(500);
	analogWrite(ledPin, 191);
	delay(500);
	analogWrite(ledPin, 223);
	delay(500);
	analogWrite(ledPin, 255);
	delay(500);
}