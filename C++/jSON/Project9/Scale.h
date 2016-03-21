#pragma once
#include "Value.h"
class Scale :
	public Value
{

public:
	 int value;
	Scale(unsigned int value_) :value(value_){};
	~Scale();
	operator int(){ return value; };
	virtual void show(){};
};

