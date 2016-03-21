#pragma once
#include <string>
#include <map>
#include "Trait.h"
class Ratee
{
public:

	const std::string name;
	std::map<trait_numb, int> result;

	Ratee(std::string& name_) : name(name_){};
};

