#include "HardwareSerial.h"

//IF (year divisible by 4 is equal to 0) and (year divisible by 100 is not equal to 0) or (year divisible by 400 is equal to 0)
int CalculateLeapYear(int year) {
	int resualt = false;
	
	if (((year % 4 == 0) && (year % 100!= 0)) || (year%400 == 0)) {
		resualt = true;
	}
	
	return resualt;
}