#include <Arduino.h>
#include <DHT.h>
#include <DHT_U.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DS3231.h>

//Clock
DS3231 clock;
RTCDateTime dt;

//OLED
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define OLED_RESET 4
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
//


//DHT
#define DHTPIN 8  
#define DHTTYPE DHT11  

DHT dht(DHTPIN, DHTTYPE);
//

char grad = 0xF7;

//Millis
unsigned long previousMillis = 0;
unsigned long previousMillisTime = 0;

const long timeDate = 500;
const long interval = 10000;

bool intervalBool = false;
//

void DisplayTime();

void DisplayTemp(int h, int t);

String zeroReturn(int time);

void setup() {
	Serial.begin(9600);
	
	display.setTextSize(2);
	
	display.setTextColor(WHITE);
	
	if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
	{
		Serial.println(F("SSD1306 allocation failed"));
		for(;;);
	}
	
	clock.begin();
	
	clock.setDateTime(2022,6,8,11,16,0);
	
	dht.begin();
}



void loop() {
	unsigned long currentMillis = millis();
	
	dt = clock.getDateTime();
	
	
	int h = dht.readHumidity();

	int t = dht.readTemperature();

	int hic = dht.computeHeatIndex(t, h, false);
	
	if (isnan(h) || isnan(t)) {
		Serial.println(F("Failed to read from DHT sensor!"));
		return;
	}


	if (currentMillis - previousMillis >= interval)
	{
		previousMillis =  currentMillis;
		
		intervalBool = !intervalBool;
	}
	
	
	if (currentMillis - previousMillisTime >= timeDate)
	{
		previousMillisTime =  currentMillis;

		intervalBool == false ? DisplayTime() :  DisplayTemp(h, t);
	}
}


String zeroReturn(int time) {
	String zeroRet = String(time);
	return time <=9 ? '0' + zeroRet : zeroRet;
}

void DisplayTime()
{
	display.clearDisplay();


	display.setCursor(0,0);


	display.print(zeroReturn(dt.year)); display.print("/");

	display.print(zeroReturn(dt.month)); display.print("/");
	
	display.print(zeroReturn(dt.day));
	
	
	display.setCursor(0,20);


	display.print(zeroReturn(dt.hour)); display.print(":");
	
	display.print(zeroReturn(dt.minute)); display.print(":");
	
	display.print(zeroReturn(dt.second));


	display.display();
}

void DisplayTemp(int h, int t)
{
	display.setCursor(0,0);
	
	display.clearDisplay();
	
	display.print(F("Hum: "));
	display.print(h);
	display.print(F("%"));
	
	display.setCursor(0,20);
	
	display.print(F("Temp: "));
	display.print(t);
	display.print(grad);
	display.print(F("C "));
	
	display.display();
}
