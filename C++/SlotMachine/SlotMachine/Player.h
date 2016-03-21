#pragma once

#include "SlotMachine.h"
#include <iostream>
#include <string>
#include <sstream>

class SlotMachine;

class Player
{

private:

	unsigned int sum;

public:

	Player(unsigned int initialSum) : sum(initialSum) { };

	void play(SlotMachine& machine, unsigned int bet);
	std::string toString();
	void Win(unsigned int money);

};

