#include <Arduino.h>

float var1 = 47;

float *ptr = &var1;

char navn[] = "Frederik\r\n";

char *ptrString = navn;

void setup(){
	Serial.begin(9600);
	
	Serial.println(*ptr);
	
	//3. Hvad mangler der i dette program? Tilføj den manglende linje:
	
	//int var = 0;
	//int* pName;
	//*pName = 33;
	//return 0;
	
	//4. Hvad skal der skrives (i pointer-notation) for at ch bliver lig med n’et i tekststrengen?
	
	//char string[] = "Lene";
	//char ch = *(string + 2);

	char str[] = "Frederik";
	char navn = *(str + 2);
	Serial.println(navn);
	
	
	char *n = str + 7;
	
	for (int i = 0; i < 8; i++)
	{
		Serial.println(*n);
		n--;
	}
}

void loop(){

}