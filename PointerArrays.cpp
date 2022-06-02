/* 5. PointersArrays */

#include <Arduino.h>

void PrintCharArray(char str[]);
void PrintIntArray(long *ptr, long length);

void setup()
{
	Serial.begin(115200);
	
	char text[] = "Start pump\r\n";
	long samples[] = {115, 2000, 95, 9 };

	PrintCharArray(text);
	PrintIntArray(samples, sizeof(samples) / 4);
}

void loop()
{
}

void PrintCharArray(char str[])
{
	int i = 0;

	while (str[i] != 0)
	{
		Serial.print(str[i]);
		i++;
	}
	while (*str != 0)
	{
		Serial.print("Content: ");
		Serial.print(*str); Serial.println();
		Serial.print("Address: ");
		Serial.print((unsigned long)str); Serial.println();
		str++;
	}
}

void PrintIntArray(long *ptr, long length)
{
	int i;
	Serial.println("-----------------------------------------");
	for (i = 0; i < length; i++)
	{
		Serial.println(ptr[i]);
	}
	Serial.println("-----------------------------------------");
	for (i = 0; i < length; i++)
	{
		Serial.print("Content: ");
		Serial.println(*ptr); Serial.println();
		Serial.print("Address: ");
		Serial.println((unsigned long)ptr);	Serial.println();
		ptr++;
	}
}