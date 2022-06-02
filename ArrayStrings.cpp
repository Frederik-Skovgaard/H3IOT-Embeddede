#include <Arduino.h>

byte array[3] = {7, 9, 13};
byte index;

char navn[] = { 'F', 'r', 'e', 'd', 'e', 'r', 'i', 'k', '\0'};

void setup()
{
	Serial.begin(115200);
	
	for (index = 0; index < sizeof(array); index++)
	{
		Serial.println(array[index]);
	}
	
	Serial.println(navn);
	
	
	
	for (index = sizeof(navn) - 2; index >= 0; index--)
	{
		Serial.println(navn[index]);
		
		if (index == 0)
		{
			break;
		}
	}

}

void loop()
{
	
}