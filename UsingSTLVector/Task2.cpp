#include "Task2.h"

City::~City()
{
}

City::City()
	: City(std::string("Unknown country"), std::string("Unknown city"), 0)
{
}

City::City(const std::string& country, const std::string& name, unsigned population)
	: cityCountry(country), cityName(name), cityPopulation(population)
{
}

std::string City::GetCountry() const
{
	return cityCountry;
}

std::string City::GetName() const
{
	return cityName;
}

unsigned City::GetPopulation() const
{
	return cityPopulation;
}

void City::PrintTo(std::ostream& os) const
{
	os << cityCountry << ' ' << cityName << ' ' << cityPopulation << std::endl;
}

void City::ReadFrom(std::istream& is)
{
	is >> cityCountry >> cityName >> cityPopulation;
}

std::istream& operator>>(std::istream& is, City& C)
{
	C.ReadFrom(is);
	return is;
}

std::ostream& operator<<(std::ostream& os, const City& C)
{
	C.PrintTo(os);
	return os;
}
