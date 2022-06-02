/* 1. ArrayDemo */
#include <Arduino.h>

void setup()
{
	Serial.begin(115200);
	
	int num_list[5] = {34, 789, 327, 1000, 45};
	int index;

	for (index = 0; index < 5; index++)
	{
		Serial.print("Element "); Serial.print(index); Serial.print(" = "); Serial.println(num_list[index]);
	}
}

void loop()
{}