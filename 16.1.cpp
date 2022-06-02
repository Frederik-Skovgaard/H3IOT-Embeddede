#include <Arduino.h>




void setup()
{
	Serial.begin(115200);	
	
	int value = 100;
	int *ptr = &value;

	int valuecopy = *ptr;
	
	int newValue = 42;
	
	Serial.print("Content of value: 0x"); Serial.println((unsigned int)&value, HEX);
	Serial.print("Content of value: "); Serial.println((unsigned int)value);
	
	Serial.print("Content of ptr: 0x"); Serial.println((unsigned int)ptr, HEX);
	Serial.print("Content of ptr: "); Serial.println((unsigned int)*ptr);
	
	*ptr = newValue;
	
	Serial.print("Content of new value: 0x"); Serial.println((unsigned int)ptr, HEX);
	Serial.print("Content of new value: "); Serial.println((unsigned int)*ptr);
	
}

void loop()
{
	
}