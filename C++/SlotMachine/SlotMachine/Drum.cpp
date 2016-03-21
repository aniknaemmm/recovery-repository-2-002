#include "Drum.h"
#include <vector>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <random>      
#include <chrono>
#include <iostream>

Drum::Drum(unsigned int size_,unsigned int line_) : size(size_), line(line_), current(0){

	std::vector<char> symbols(size);
	symbols.assign(size, 25);
	symbols[0] = 6;
	char symb = 5;

	for (unsigned int i = 1; i < size; ++i)
	{
		//если закончились пятерки (10%)
		if (i <= size / 10)
		{
			symb = 4;
		}
		//если закончились четверки (25%)
		else if (i <= size / 4)
		{
			symb = 3;
		}
		//если закончились тройки (40%)
		else if (i <= size * 4 / 10)
		{
			symb = 2;
		}
		//если закончились двойки (60%)
		 else if (i <= size * 6 / 10)
		{
			symb = 1;
		}
		//если закончились единицы (80%)
		else 
		{
			symb = 0;
		}

		symbols[i] += symb;
	}

	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	
	// experiment to three tapes
	for (unsigned int i = 0; i < line; i++)
	{
		shuffle(symbols.begin(), symbols.end(), std::default_random_engine(seed));
		drum.push_back(symbols);
	}
};

std::vector<double> Drum::show()
{
	int link=(size-1), next=0,inc=0;
	std::vector<double> temp;
	current = (++current) % size;
	std::cout << "-----------" << std::endl;
	if ((current - 1) != -1){
		link = current - 1;
	}
	if ((current + 1) != size){
		next = current + 1;
	}

	for (auto F : drum)
	{
		std::cout << "|" << F[link];
	}
	std::cout << "|" << std::endl;
	std::cout << "-----------" << std::endl;
	for (auto F : drum)
	{	
		temp.push_back(F[current]);
		std::cout << "|" << F[current];
	}
	std::cout << "|" << std::endl;
	std::cout << "-----------" << std::endl;
	
	for (auto F : drum)
	{
		std::cout << "|" << F[next];
	}
	std::cout << "|" << std::endl;
	std::cout << "-----------" << std::endl;
	return temp;
};