#pragma once
#include <string>

struct Data{
	std::string* s;
	struct data *link;
};

class Assati
{
	Data data;

public:
	Assati();
	~Assati();

	double operator[](char* index);

};

