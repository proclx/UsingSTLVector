#pragma once
#include <iostream>
#include <string>

class City
{
private:
	std::string cityCountry;
	std::string cityName;
	unsigned cityPopulation;
public:
	~City();
	City();
	City(const std::string& country, const std::string& name, unsigned population);

	std::string GetCountry() const;
	std::string GetName() const;
	unsigned GetPopulation() const;

	void PrintTo(std::ostream& os) const;
	void ReadFrom(std::istream& is);

	friend std::istream& operator>>(std::istream& is, City& C);
};

std::ostream& operator<<(std::ostream& os, const City& C);

