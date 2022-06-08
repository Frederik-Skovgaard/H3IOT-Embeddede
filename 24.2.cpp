/* 3. FormattedData.cpp
	Print values in various formats to the serial port
*/
#include <Arduino.h>

char chrValue  = 65;  // these are the starting values to print
byte byteValue = 65;
int intValue   = 65;
float floatValue = 65.0;
char c1 = 4;
char c2 = 210;

void setup()
{
	while(!Serial); // Wait until serial port's open on Leonardo and SAMD boards
	Serial.begin(115200);
}

void loop()
{
	Serial.print("chrValue:   ");
	Serial.print(chrValue); Serial.print(" ");
	Serial.write(chrValue); Serial.print(" ");
	Serial.print(chrValue, DEC);
	Serial.println();

	Serial.print("byteValue:  ");
	Serial.print(byteValue); Serial.print(" ");
	Serial.write(byteValue); Serial.print(" ");
	Serial.print(byteValue, DEC);
	Serial.println();

	Serial.print("intValue:   ");
	Serial.print(intValue); Serial.print(" ");
	Serial.print(intValue, DEC); Serial.print(" ");
	Serial.print(intValue, HEX); Serial.print(" ");
	Serial.print(intValue, OCT); Serial.print(" ");
	Serial.print(intValue, BIN);
	Serial.println();

	Serial.print("floatValue: ");
	Serial.println(floatValue);
	Serial.println();

	delay(1000); // delay a second between numbers
	chrValue++;  // to the next value
	byteValue++;
	intValue++;
	floatValue += 1;
}