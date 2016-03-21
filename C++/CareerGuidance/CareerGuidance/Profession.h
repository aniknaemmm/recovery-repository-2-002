#pragma once
#include <string>
#include <list>
#include <vector>
typedef size_t trait_numb;



class Profession
{
public:
	const std::string name;
	std::list<trait_numb> traits;
	static std::vector<Profession> professions;

    Profession(std::string &name_): name(name_) {}

	static void Init();

    void AddTrait(trait_numb trait) { traits.push_back(trait); }

}; 

