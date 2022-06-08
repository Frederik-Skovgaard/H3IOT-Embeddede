#include <Arduino.h>

int ledPin = 6;
String inputString = "";         // a String to hold incoming data
bool stringComplete = false;	 // whether the string is complete

char numbs[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

int mili = 100;
int interval;


void setup()
{
	Serial.begin(115200);
	pinMode(ledPin, OUTPUT);
	
	inputString.reserve(200);		// reserve 200 bytes for the inputString
}

void loop()
{	
	// print the string when a newline arrives:
	if (stringComplete)
	{
		Serial.println(inputString);
		
		for (int i = 0; i > sizeof(numbs); i++)
		{
			if (inputString == numbs[i])
			{
				interval =  100 * (int)numbs[i];
			}
		}
		
		// clear the string:
		inputString = "";
		stringComplete = false;
	}
	
	digitalWrite(ledPin, HIGH);
	delay(interval);
	digitalWrite(ledPin, LOW);
	delay(interval);
}


void serialEvent()
{
	while (Serial.available())
	{
		// get the new byte:
		char inChar = Serial.read();
		// add it to the inputString:
		inputString += inChar;
		// if the incoming character is a newline, set a flag so the main loop can do something about it:
		if (inChar == '\n')
		{
			stringComplete = true;
		}
	}
}

