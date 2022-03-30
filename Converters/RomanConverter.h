#ifndef ROMANCONVERTER_H
#define ROMANCONVERTER_H
#include <string>
#include "Converter.h"
class RomanConverter : public Converter{
private:
	bool validate(int);
	bool validate(std::string);
public:
	RomanConverter();
	std::string toRomanNumerals(int);
	int toArabicNumerals(std::string);
	

};

#endif //ROMANCONVERTER_H
