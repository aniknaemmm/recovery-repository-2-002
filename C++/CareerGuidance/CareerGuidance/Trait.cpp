#include "Trait.h"
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include "ParseCSVString.h"
#include <iostream>



std::vector<Trait> Trait::traits;

void Trait::Init()
{
	// check
	if (traits.size())
		return;

	std::string buffer, number;
	std::ifstream file;
	file.open("../Data/Traits.csv");
	if (!file.is_open())
		throw std::exception("Error: file(Question.csv) is not opened!\n");
	int counter = 0, question_num;

	while (!file.eof())
	{
		std::getline(file, buffer);
		std::vector<std::string> data = ParseCSVString(buffer);
		if (!data.size())
			break;

		number = data[0];
		std::stringstream ss(number);
		ss >> question_num;

		if (counter == question_num)
		{
			Trait trait(data[1]);
			traits.push_back(trait);
			counter++;
		}
		else
		{
			file.close();
			throw std::exception("Error: file(Question.csv) content!\n");
		}
	}
	file.close();
}
