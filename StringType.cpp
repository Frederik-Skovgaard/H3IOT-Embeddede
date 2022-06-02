#include <Arduino.h>

String hello = String("Hello");
String friends = String("friends");

String combo = String(hello + " " + friends);


void setup()
{
	Serial.begin(115200);
	
	Serial.print(hello); Serial.print(" "); Serial.println(hello.length());
	Serial.print(friends); Serial.print(" "); Serial.println(friends.length());
	
	Serial.print(combo); Serial.print(" "); Serial.println(combo.length());
	
	Serial.print(friends.charAt(2));

}

void loop()
{
	
}