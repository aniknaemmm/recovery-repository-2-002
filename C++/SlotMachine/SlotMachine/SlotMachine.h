#pragma once
#include "Player.h"
#include "Drum.h"
#include <string>
#include <iostream>
#include <cstdlib>


class SlotMachine
{
private:

	int win;
	unsigned int bet;
	unsigned int Summ;
	Drum drum;

	enum st	{readyToBet = 0, readyToGame, readyResult} state;

public:

	SlotMachine(unsigned int money,unsigned int size_drum ,unsigned int line_drum) : Summ(money), state(readyToBet), drum(size_drum,line_drum) { };
	
	std::string toString();
	void         makeBet(unsigned int bet);
	unsigned int getMoney();
	void         startGame();
/*	void result(Player& player)
	{
		//std::cout << player.toString() << std::endl;
	};*/
};

