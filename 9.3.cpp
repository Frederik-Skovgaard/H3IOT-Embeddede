#include <Arduino.h>

const int switchPin = 7;
const int ledPin = 6;

int ledState = HIGH;

int buttonState;
int lastButtonState = LOW;

const char lightOff = 'Lights off';
const char lightOn = 'Lights on';

unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;

void setup() {
	pinMode(switchPin, INPUT_PULLUP);
	pinMode(ledPin, OUTPUT);
	
	digitalWrite(ledPin, ledState);
	
	Serial.begin(9600);
}

void loop() {
	int reading = digitalRead(switchPin);
	
	if (reading != lastButtonState)
	{
		lastDebounceTime = millis();
	}
	
	if ((millis() - lastDebounceTime) > debounceDelay)
	{
		if (reading != buttonState)
		{
			buttonState = reading;
			
			if (buttonState == HIGH)
			{
				ledState = !ledState;
			}
		}
	}
	
	if (ledState == HIGH)
	{
		Serial.println(lightOn);
	}
	else
	{
		Serial.println(lightOff);
	}
	
	digitalWrite(ledPin, ledState);
	lastButtonState = reading;
}