#include "Utilities.h"

unsigned AllPopulation(const std::vector<City>& v)
{
	unsigned result = 0;
	for (const City& C : v)
	{
		result += C.GetPopulation();
	}
	return result;
}