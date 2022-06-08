#include <Arduino.h>
#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET 4 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define SS_PIN 53
#define RST_PIN 8

Servo myservo;

int cardArray[3][4] = {{64, 48, 118, 165}, {138, 238, 89, 211}, {64, 152, 109, 165}};
	
bool trufals;

MFRC522 rfid(SS_PIN, RST_PIN); // Instance of the class

void setup() { 
  Serial.begin(9600);
  SPI.begin(); // Init SPI bus
  rfid.PCD_Init(); // Init MFRC522 
  
	display.clearDisplay();
	
	myservo.attach(9);
	
	myservo.write(0);
	
	// SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
	if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
	{ // Address for 128x64
		Serial.println(F("SSD1306 allocation failed"));
		for(;;); // Don't proceed, loop forever
	}
	
}
 
void loop() {

  // Look for new cards
  if ( ! rfid.PICC_IsNewCardPresent())
    return;

  // Verify if the NUID has been readed
  if ( ! rfid.PICC_ReadCardSerial())
    return;

	int index = 0;

	for (index = 0;index < 4; index++)
	{
		if (rfid.uid.uidByte[0] == cardArray[index][index] || rfid.uid.uidByte[1] == cardArray[index][(index + 1)]|| rfid.uid.uidByte[2] == cardArray[index][(index + 2)] || rfid.uid.uidByte[3] == cardArray[index][(index + 3)] )
		{
			display.clearDisplay();
			
			display.setTextSize(1); // Normal 1:1 pixel scale
			display.setTextColor(WHITE); // Draw white text
			display.setCursor(0,0); // Start at top-left corner
			
			Serial.println(F("Access Granted"));
			display.display();
			
			delay(500);
			
			display.setCursor(1,0); // Start at top-left corner
			
			Serial.println(F("Door opens"));
			display.display();
			
			
			trufals = true;
			
			for (int i = 0; i < 180; i++)
			{
				myservo.write(i);
				delay(20);
			}
			
			delay(2000);
			
			display.setCursor(2,0); // Start at top-left corner
			
			Serial.println(F("Door closing"));
			display.display();
			
			for (int i = 179; i >= 0; i--)
			{
				myservo.write(i);
				delay(20);
			}
			break;
		}
	}

	if (trufals == false)
	{
		display.clearDisplay();
		
		display.setCursor(3,0); // Start at top-left corner
		
		Serial.println(F("Access Denied"));
		display.display();
	}
	
	trufals = false;
	
	 // Halt PICC
	 rfid.PICC_HaltA();

	 // Stop encryption on PCD
	 rfid.PCD_StopCrypto1();
 
}
 

 
