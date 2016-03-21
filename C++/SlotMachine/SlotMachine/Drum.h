#pragma once

#include <cstdlib>
#include <vector>
#include <algorithm>
#include <random>      
#include <chrono>

using std::vector;

class Drum
{
private:

	unsigned int size, line, current;
	vector<vector<char>> drum;

public:
	
	Drum(unsigned int size_, unsigned int line_);
	std::vector<double> show();

};

