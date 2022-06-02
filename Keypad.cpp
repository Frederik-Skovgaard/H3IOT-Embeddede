#include <Arduino.h>
#include <Keypad.h>
	
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns

//define the symbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
	{'1','2','3','A'},
	{'4','5','6','B'},
	{'7','8','9','C'},
	{'*','0','#','D'}
};

byte rowPins[ROWS] = {30, 31, 33, 32}; //connect to the row pin outs of the keypad
byte colPins[COLS] = {34, 35, 36, 37}; //connect to the column pin outs of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void setup(){
	Serial.begin(9600);
}

void loop(){
	char customKey = customKeypad.getKey();
	if (customKey){
		Serial.println(customKey);
	}
}