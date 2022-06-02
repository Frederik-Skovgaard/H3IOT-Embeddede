#include <Arduino.h>

const int pinLed = 2;

int ledState = LOW;

unsigned long previousMillis = 0;

const long sosLine = 1000;
const long sosDot = 500;

int dotCounter = 0;
int lineCounter = 0;


void setup() {
	pinMode(pinLed, OUTPUT);
}

void loop() {
	unsigned long currentMillis = millis();
	
	if (currentMillis - previousMillis >= sosDot && dotCounter < 6)
	{
		previousMillis = currentMillis;
		
		if (ledState == LOW)
		{
			ledState = HIGH;
		}
		else {
			ledState = LOW;
		}
		
		digitalWrite(pinLed, ledState);
		
		dotCounter = dotCounter + 1;
	}
	else if (currentMillis - previousMillis >= sosLine && lineCounter < 6)
	{
		previousMillis = currentMillis;
		
		if (ledState == LOW)
		{
			ledState = HIGH;
		}
		else {
			ledState = LOW;
		}
		
		digitalWrite(pinLed, ledState);
		
		lineCounter = lineCounter + 1;
		
		if (lineCounter == 6) {
			lineCounter = 0;
			dotCounter = 0;
		}
	}
	
}