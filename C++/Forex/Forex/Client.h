#pragma once
#include "Buddy.h"

class Client :	public Buddy
{
public:
	Client(Stock& st) : Buddy(st) {};
	~Client();
	virtual void act();
};

