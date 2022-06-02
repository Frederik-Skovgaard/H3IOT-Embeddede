#include <Arduino.h>
#include <LiquidCrystal.h>

//Initialize the library by associating any needed LCD interface pin
//With the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

//Symbol for celsius
char celsius = 0xDF;

//Pins
int red = 10;
int green = 9;
int blue = 8;

//Will store last time the display was updated
unsigned long previousMillis = 0;

//Interval at which to print
unsigned long interval = 500;

//Change color based on temp
float hot = 28.0;
float cold = 25.0;

//Math for calculating the analog output to celsius
float MeasureTemperatur(float reading) {
	float temp = log(10000.0 * (1024.0/reading - 1));
	float tempK = 1/(0.001129148 + (0.000234125 + (0.0000000876741 * temp * temp)) * temp);
	float tempC = tempK - 273.15;
	return tempC;
}

void setup() {
	//Add pin
	pinMode(red, OUTPUT);
	pinMode(green, OUTPUT);
	pinMode(blue, OUTPUT);
	
	//Default values
	analogWrite(red, 0);
	analogWrite(green, 0);
	analogWrite(blue, 0);
	
	//Print to display
	lcd.begin(16, 2);
	lcd.print("Temp");
	
	lcd.setCursor(11, 0);
	lcd.print(celsius);
	lcd.print("C");
	
	//Add serial terminal
	Serial.begin(9600);
}

void loop() {
	//Get the Analog input from the temp
	float reading = analogRead(A1);
	
	//Variable for storing how many milliseconds the program has been running
	unsigned long currentMillis = millis();
	
	//Get value of analog in celsius, then round out the results
	float resualt = MeasureTemperatur(reading);
	float resualtRounded = ((int)(resualt * 10.0 + 0.5) / 10.0);
	
	
	//Every one seconds it updates the display
	if (currentMillis - previousMillis >= interval) {
		previousMillis = currentMillis;
		
		lcd.setCursor(6, 0);
		lcd.print(resualtRounded);
		
		//If temp is greater then or equal to hot value then the light is red
		if (resualtRounded >= hot) {
			analogWrite(red, 255);
			analogWrite(green, 0);
			analogWrite(blue, 0);
		}
		//If temp greater then cold and less then hot
		else if (resualtRounded > cold && resualtRounded < hot)
		{
			analogWrite(red, 255);
			analogWrite(green, 20);
			analogWrite(blue, 0);
		}
		//If temp is under or equal to cold value then the light is blue
		else if (resualtRounded <= cold)
		{
			analogWrite(red, 0);
			analogWrite(green, 0);
			analogWrite(blue, 255);
		}
	}
	
	
}
