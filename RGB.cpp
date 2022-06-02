#include <Arduino.h>

const int red = 10;
const int green = 9;
const int blue = 8;

const int interval = 200;


void setup() {
	pinMode(red, OUTPUT);
	pinMode(green, OUTPUT);
	pinMode(blue, OUTPUT);
	
	analogWrite(red, 0);
	analogWrite(green, 0);
	analogWrite(blue, 0);
}

void loop() {
	analogWrite(red, 148);
	analogWrite(green, 0);
	analogWrite(blue, 211);
	delay(interval);
	
	analogWrite(red, 75);
	analogWrite(green, 0);
	analogWrite(blue, 130);
	delay(interval);
	
	analogWrite(red, 0);
	analogWrite(green, 0);
	analogWrite(blue, 255);
	delay(interval);
	
	analogWrite(red, 0);
	analogWrite(green, 255);
	analogWrite(blue, 0);
	delay(interval);
	
	analogWrite(red, 255);
	analogWrite(green, 255);
	analogWrite(blue, 0);
	delay(interval);
	
	analogWrite(red, 255);
	analogWrite(green, 127);
	analogWrite(blue, 0);
	delay(interval);
	
	analogWrite(red, 255);
	analogWrite(green, 0);
	analogWrite(blue, 0);
	delay(interval);
}