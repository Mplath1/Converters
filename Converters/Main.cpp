#include <iostream>
#include "TemperatureConverter.h"
#include "RomanConverter.h"

//TODO: Build user option 
int main()
{
	
	TemperatureConverter tempConverter;
	std::cout << tempConverter.toFarenheit(0) << "F"<< std::endl;
	std::cout << tempConverter.toCelsius(32) << "C" << std::endl;
	RomanConverter roman;
	std::cout << roman.toRomanNumerals(679) << std::endl;
	std::cout << roman.toArabicNumerals("XXXVII") << std::endl;
}
