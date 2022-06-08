#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DS3231.h>


DS3231 clock;
RTCDateTime dt;

#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 64 

#define OLED_RESET 4 
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

String zeroReturn(int time);

void setup()
{
	Serial.begin(9600);
	
	
	if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
	{
		Serial.println(F("SSD1306 allocation failed"));
		for(;;);
	}
	
	clock.begin();

	clock.setDateTime(__DATE__, __TIME__);
}

void loop()
{
	dt = clock.getDateTime();
	
	display.clearDisplay();

	display.setTextSize(2);
	display.setTextColor(WHITE); 
	display.setCursor(0,0);

	display.print(zeroReturn(dt.year)); display.print("/");    
	   

	display.print(zeroReturn(dt.month)); display.print("/");
	
	
	display.print(zeroReturn(dt.day));
	
	
	
	display.setCursor(0,20);
	

	display.print(zeroReturn(dt.hour)); display.print(":"); 
	
	  

	display.print(zeroReturn(dt.minute)); display.print(":");
	

	display.print(zeroReturn(dt.second));

	display.display();
	delay(800);
}

String zeroReturn(int time) {
	String zeroRet = String(time);
	return time <=9 ? '0' + zeroRet : zeroRet;
}