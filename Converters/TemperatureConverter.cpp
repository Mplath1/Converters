#include "TemperatureConverter.h"

TemperatureConverter::TemperatureConverter()
{
}

double TemperatureConverter::toCelsius(double farenheitTemp)
{
	return (farenheitTemp - 32) * (5 / 9);
}

double TemperatureConverter::toFarenheit(double celsiusTemp)
{
	return (celsiusTemp * (9 / 5)) + 32;
}