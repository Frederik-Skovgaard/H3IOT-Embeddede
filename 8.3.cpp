#include <Arduino.h>

int pinArray[] = {2, 3, 4, 5, 6, 7, 8, 9};
int count = 0;

void setup() {
	for(count = 0; count < sizeof(pinArray)/2; count++) {
		pinMode(pinArray[count], OUTPUT);
	}
}

void loop() {

	for (count = 0; count < sizeof(pinArray) /2; count++) {
		digitalWrite(pinArray[count], HIGH);
		delay(75);
		digitalWrite(pinArray[count], LOW);
	}

	for (count = sizeof(pinArray) / 2 - 1; count >= 0; count--) {
		digitalWrite(pinArray[count], HIGH);
		delay(75);
		digitalWrite(pinArray[count], LOW);
	}
}