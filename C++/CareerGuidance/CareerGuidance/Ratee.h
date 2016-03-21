#pragma once
#include <string>
#include <map>
#include "Trait.h"




typedef size_t trait_numb;
typedef size_t prof_num; // profession number


class Ratee
{
public:
	const std::string name;
	std::map<trait_numb, int> result;
    std::map<prof_num, int> final_result;

	Ratee(std::string &name_) : name(name_)
	{
		for (trait_numb i = 0; i < Trait::traits.size(); i++)
			result[i] = 0;
	}

};

