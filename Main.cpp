#include <Arduino.h>

//Step 1: Take integer variable year and assigned it with a value
//Step 2: Check if year is divisible by 4 but not 100, Turn on led
//Step 3: Check if year is divisible by 400, Turn on led
//Step 4: Check if currentMillis minus previous millis is greater or equal to interval
//Step 5: Assign previousMillis to currentMillis
//Step 6: Check if state is equal to low, assign value high to ledState
//Step 7: Else assign value low to ledState
//Step 8: Turn led on/off depending on ledState


const int ledPin = 2;
int year = 2024;

//Variables will change:
int ledState = LOW;    
   
//will store last time LED was updated
unsigned long previousMillis = 0;       

//Interval at which to blink
const long interval = 1000;

void setup() {
	//Set the digital pin as output
	pinMode(ledPin, OUTPUT);
	
	digitalWrite(ledPin, LOW);
}


void loop() {
	
	//The interval at which you want to blink the LED.
	unsigned long currentMillis = millis();

	//IF (year divisible by 4 is equal to 0) and (year divisible by 100 is not equal to 0) or (year divisible by 400 is equal to 0)
	//IF (current millis minus previous millis is greater or equal to interval)
	//Previous millis is equal to current millis
	//IF (led state is equal to low)
	//Turn on led
	//Else
	//Turn off led

	if (((year % 4 == 0) && (year % 100!= 0)) || (year%400 == 0)) {
		if (currentMillis - previousMillis >= interval) {
			// save the last time you blinked the LED
			previousMillis = currentMillis;
		
			// if the LED is off turn it on and vice-versa:
			if (ledState == LOW) {
				ledState = HIGH;
				} else {
				ledState = LOW;
			}

			// set the LED with the ledState of the variable:
			digitalWrite(ledPin, ledState);
		}
	}
}


