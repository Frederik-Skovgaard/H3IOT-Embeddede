#include <Arduino.h>
#include <Servo.h>

Servo myservo;
int potpin = A1;

int val;

void setup(){
	
	myservo.attach(9);
	
	
	//myservo.write(0);
	//delay(2000);
}

void loop(){
	
	val = analogRead(potpin);
	
	val = map(val, 0, 1023, 0, 180);
	
	myservo.write(val);
	delay(15);
	
	//for (int i = 0; i < 180; i++)
	//{
		//myservo.write(i);
		//delay(20);
	//}
	//
	//for (int i = 179; i >= 0; i--)
	//{
		//myservo.write(i);
		//delay(20);
	//}
}