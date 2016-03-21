#pragma once
#include "Value.h"
#include <vector>
class myList :
	public Value
{
public:
	std::vector<Value*> values;
	myList(std::vector<Value*> value_) :values(value_){};
	~myList();
};

