#ifndef TEMPERATURECONVERTER_H
#define TEMPERATURECONVERTER_H
#include "Converter.h"
class TemperatureConverter : public Converter {

public:
	TemperatureConverter();
	double toCelsius(double);
	double toFarenheit(double);

};

#endif //TEMPERATURECONVERTER_H

