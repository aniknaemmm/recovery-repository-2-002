#pragma once
#include "Stock.h"
class Buddy
{
public:
	Stock& stock;
	virtual void act() = 0;
	Buddy(Stock& st) : stock(st) {};
};
