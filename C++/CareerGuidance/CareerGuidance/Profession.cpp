#include "Profession.h"

#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include "ParseCSVString.h"
#include <iostream>
#include <map>


std::vector<Profession> Profession::professions;

void Profession::Init()
{
	// check
	if (professions.size())
		return;

	std::string buffer, number;
	std::ifstream file;
	file.open("../Data/Professions.csv");

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
			Profession prof(data[1]);
			for (auto it = data.begin() + 2; it != data.end(); it++)
			{
				int trait;
				number = *it;
				std::stringstream ss(number);
				ss >> trait;
				prof.AddTrait(trait);
			}
			professions.push_back(prof);
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
