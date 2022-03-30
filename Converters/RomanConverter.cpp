#include "RomanConverter.h"

RomanConverter::RomanConverter(){
}

std::string RomanConverter::toRomanNumerals(int arabicNumerals){
	if (validate(arabicNumerals)) {
		int thousands = arabicNumerals / 1000;
		arabicNumerals = arabicNumerals % 1000;
		int fiveHundreds = arabicNumerals / 500;
		arabicNumerals = arabicNumerals % 500;
		int hundreds = arabicNumerals / 100;
		arabicNumerals = arabicNumerals % 100;
		int fifties = arabicNumerals / 50;
		arabicNumerals = arabicNumerals % 50;
		int tens = arabicNumerals / 10;
		arabicNumerals = arabicNumerals % 10;
		int fives = arabicNumerals / 5;
		arabicNumerals = arabicNumerals % 5;
		int ones = arabicNumerals / 1;

		std::string roman;

		while (ones > 0) {
			if (ones < 4) {
				roman.insert(0, "I");
				ones--;
			}
			else {
				if (fives) {
					roman.insert(0, "IX");
					fives = 0;
				}
				else {
					roman.insert(0, "IV");
				}
				ones = 0;
			}
		}
		while (fives > 0) {
			roman.insert(0, "V");
			fives--;
		}

		while (tens > 0) {
			if (tens < 4) {
				roman.insert(0, "X");
				tens--;
			}
			else {
				if (fifties) {
					roman.insert(0, "XC");
				}
				else {
					roman.insert(0, "XL");
					fifties = 0;
				}
				fifties = 0;
				tens = 0;
				break;
			}
		}

		while (fifties > 0) {
			roman.insert(0, "L");
			fifties--;
		}

		while (hundreds > 0) {
			if (hundreds < 4) {
				roman.insert(0, "C");
				hundreds--;
			}
			else {
				if (thousands && fiveHundreds || fiveHundreds) {
					roman.insert(0, "CM");
					fiveHundreds = 0;
				}
				else {
					roman.insert(0, "CD");
				}
				hundreds = 0;
			}
		}

		while (fiveHundreds > 0) {
			roman.insert(0, "D");
			fiveHundreds--;
		}

		while (thousands > 0) {
			roman.insert(0, "M");
			thousands--;
		}
		return roman;
	}

	return "None";
}

int RomanConverter::toArabicNumerals(std::string romanNumerals){
	//if (validate(romanNumerals)) {
		char* token = &romanNumerals[romanNumerals.length() - 1];

		int length = romanNumerals.length();
		int arabicNumerals = 0;

		do {
			switch (*token) {
				case 'I':
					if (arabicNumerals == 0 || arabicNumerals % 5 != 0) {
						arabicNumerals += 1;
					}else{ 
						arabicNumerals -= 1;
					}
					break;
				case 'V':
					arabicNumerals += 5;
					break;
				case 'X':
					if (arabicNumerals < 50) {
						arabicNumerals += 10;
					}else{
						arabicNumerals -= 10;
					}
					break;
				case 'L':
					arabicNumerals += 50;
					break;
				case 'C':
					if (arabicNumerals < 500) {
						arabicNumerals += 100;
					}else{
						arabicNumerals -= 100;
					}
					break;
				case 'D':
					arabicNumerals += 500;
					break;
				case 'M':
					arabicNumerals += 1000;
					break;
				default:
					return -1;
			}
		token--;
		length--;
		}while(length > 0);

		return arabicNumerals;
	//}
	//return -1;
}

bool RomanConverter::validate(int arabicNumerals){
	if (arabicNumerals > 0 && arabicNumerals < 4000) {
		return true;
	}
	return false;
}

[[deprecated("Redundant. Handled by switch default case in toArabicNumerals function")]]
bool RomanConverter::validate(std::string romanNumerals){
	char acceptedChars[7] = { 'M','D','C','L','X','V','I' };

	for(int i = 0; i < romanNumerals.length(); i++) {
		
	}
	return false;
}

