#pragma once
#include "Buddy.h"

class Player: public Buddy {

public:
	Player(Stock& st) : Buddy(st) {};
	~Player();
	virtual void act();
};

