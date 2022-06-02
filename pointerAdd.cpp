#include <Arduino.h>

void add(float *tal1, float *tal2, float *ptrResualt);

void setup()
{
	Serial.begin(115200);
	
	float tal1 = 5;
	float tal2 = 10;
	float result = 0;
	
	float *ptrResualt = &result;
	
	add(&tal1, &tal2, &result);
	
	Serial.print(tal1); Serial.print(" + "); Serial.print(tal2); Serial.print(" = "); Serial.println(*ptrResualt);
}

void loop()
{
	
	
}

void add(float *tal1, float *tal2, float *ptrResualt) {
	*tal1 *= 1.25;
	*tal2 *= 1.25;
	
	*ptrResualt = *tal1 + *tal2;	
}