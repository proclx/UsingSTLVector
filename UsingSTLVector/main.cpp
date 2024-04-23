#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include "Task1.h"
#include "Task2.h"
#include "Utilities.h"

int main()
{
	// first task 

	{
		// 1)
		std::vector<int> intVector1;
		intVector1.push_back(1);
		intVector1.push_back(2);
		intVector1.push_back(3);
		std::vector<double> doubleVector1;
		doubleVector1.push_back(2.01);
		doubleVector1.push_back(2.01);
		doubleVector1.push_back(2.01);
		std::cout << ScalarProduct(intVector1, doubleVector1) << std::endl;

		// 2)
		std::vector<double> doubleVector2;
		doubleVector2.push_back(2.01);
		doubleVector2.push_back(2.01);
		doubleVector2.push_back(2.01);
		std::vector<std::vector<int>> intMatrix1;
		intMatrix1.emplace_back(std::vector<int>());
		intMatrix1.emplace_back(std::vector<int>());
		intMatrix1.emplace_back(std::vector<int>());
		intMatrix1[0].push_back(1);
		intMatrix1[0].push_back(4);
		intMatrix1[1].push_back(2);
		intMatrix1[1].push_back(5);
		intMatrix1[2].push_back(3);
		intMatrix1[2].push_back(6);
		PrintVector(MatrixAndVectorProd(doubleVector2, intMatrix1));
	}

	system("pause");

	// second task

	{
		std::vector<std::vector<City>> countries;
		countries.emplace_back(std::vector<City>());
		countries.emplace_back(std::vector<City>());
		countries.emplace_back(std::vector<City>());
		std::vector<City>& ukraine = countries[0];
		std::vector<City>& poland = countries[1];
		std::vector<City>& germany = countries[2];
		std::string cities[] = { "Ukraine", "Poland", "Germany" };
		for (unsigned i = 0; i < 3; ++i)
		{
			std::ifstream fin(std::string("CitiesIn") + cities[i] + ".txt");
			std::istream_iterator<City> iter(fin);
			if (fin.good())
			{
				std::copy(iter, std::istream_iterator<City>(), std::back_inserter(countries[i]));
			}
			else
			{
				throw(std::runtime_error("Something went wrong"));
			}
			fin.close();
			std::cout << "Cities in " << countries[i][0].GetCountry() << std::endl;
			PrintVector(countries[i]);
		}
		ukraine.insert(ukraine.begin(), poland.begin(), poland.end());
		ukraine.insert(ukraine.end(), germany.begin(), germany.end());
		//std::sort(poland.begin(), poland.end(), [](const City& C1, const City& C2) {return C1.GetPopulation() < C2.GetPopulation(); });
		//			first way
		std::sort(ukraine.begin(), ukraine.end(), CompareByPopulation());
		//			second way
		PrintVector(ukraine);
		std::vector<City> onlyPoland;
		std::vector<City> onlyUkraine;
		std::vector<City> onlyGermany;
		std::copy_if(ukraine.begin(), ukraine.end(), std::back_inserter(onlyUkraine), [](const City& C) {return C.GetCountry() == "Ukraine"; });
		std::copy_if(ukraine.begin(), ukraine.end(), std::back_inserter(onlyPoland), [](const City& C) {return C.GetCountry() == "Poland"; });
		std::copy_if(ukraine.begin(), ukraine.end(), std::back_inserter(onlyGermany), [](const City& C) {return C.GetCountry() == "Germany"; });
		std::cout << "Only ukrainian cities: " << std::endl;
		PrintVector(onlyUkraine);
		std::cout << "Only polish cities: " << std::endl;
		PrintVector(onlyPoland);
		std::cout << "Only german cities: " << std::endl;
		PrintVector(onlyGermany);
		std::cout << "Total population in Ukraine: " << AllPopulation(onlyUkraine) << std::endl;
		std::cout << "Total population in Poland: " << AllPopulation(onlyPoland) << std::endl;
		std::cout << "Total population in Germany: " << AllPopulation(onlyGermany) << std::endl;
	}
	return 0;
}