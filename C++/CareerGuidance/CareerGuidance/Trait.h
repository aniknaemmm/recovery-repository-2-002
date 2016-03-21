#pragma once
#include <string>
#include <vector>


typedef size_t trait_numb;


class Trait
{
public:
	const std::string name;
	
	static std::vector<Trait> traits;
	Trait(const std::string &name_) : name(name_) {}

	static void Init();

};

