#include <Arduino.h>
#include <Servo.h>

Servo myservo;
int ledPin = 6;
const byte switchPin = 19;
volatile boolean state = LOW;


void switchPressed() {
	state = !state;
	
	digitalWrite(ledPin, state);
}

void setup(){
	pinMode(ledPin, OUTPUT);
	pinMode(switchPin, INPUT_PULLUP);
	attachInterrupt(digitalPinToInterrupt(switchPin), switchPressed, FALLING);
	
	myservo.attach(9);
}

void loop(){	 
	for (int i = 0; i < 180; i++)
	{
		myservo.write(i);
		delay(20);
	}
	
	for (int i = 179; i >= 0; i--)
	{
		myservo.write(i);
		delay(20);
	}
	
	//digitalWrite(LED_BUILTIN, HIGH);
	//delay(500);
	//digitalWrite(LED_BUILTIN, LOW);
	//delay(500);
}