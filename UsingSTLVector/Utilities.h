#pragma once
#include <vector>
#include <iostream>
#include "Task2.h"

template<typename T>
void PrintVector(const std::vector<T>& v, std::ostream& os = std::cout)
{
	os << "vector [ ";
	for (const T& C : v)
	{
		os << C << ' ';
	}
	os << "]\n";
}

class CompareByPopulation
{
public:
	bool operator()(const City& C1, const City& C2)
	{
		return C1.GetPopulation() < C2.GetPopulation();
	}
};

unsigned AllPopulation(const std::vector<City>& v);