#include <Arduino.h>

int ledPin = 2;
int buttonPin = 4;

int ledState = HIGH;         
int buttonState = HIGH;             
int lastButtonState = LOW;

int counter = 0;

unsigned long lastDebounceTime = 0; 
unsigned long debounceDelay = 50;

void setup() {
	pinMode(ledPin, OUTPUT);
	pinMode(buttonPin, INPUT_PULLUP);
	
	Serial.begin(9600);
}


void loop() {
	int reading = digitalRead(buttonPin);
	
	if (reading != lastButtonState) {
		lastDebounceTime = millis();
	}
	
	
	if ((millis() - lastDebounceTime) > debounceDelay) {
		if (reading != buttonState) {
			buttonState = reading;
			
			if (buttonState == HIGH) {
				counter = counter + 1;
				Serial.println(counter);
			}			
		}
	}
	
	lastButtonState = reading;
}