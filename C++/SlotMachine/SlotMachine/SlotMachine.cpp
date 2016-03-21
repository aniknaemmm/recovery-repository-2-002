#include "SlotMachine.h"
#include <string>
#include <sstream>
#include <cstdlib>
#include <Windows.h>
#include <ctime>


std::string SlotMachine::toString(){
	std::stringstream sum;
	sum << this->Summ;
	return sum.str();
}

void SlotMachine::makeBet(unsigned int bet) {
	if (state != readyToBet)
	{
		throw std::exception
			("in slotMachine::makeBet: not ready to bet");
	}
	// деньги попали в автомат 
	this->bet = bet;
	this->Summ += bet;
	state = readyToGame;
}

unsigned int SlotMachine::getMoney(){
	if (state != readyResult)
	{
		throw std::exception
			("in slotMachine::getMoney: not ready to pay");
	}
	this->Summ -= win;
	bet = 0;
	state = readyToBet;
	return win;
}

void SlotMachine::startGame()
{	
	win = 0;
	srand(time(NULL));
	std::vector<double> temp_drum;
	if (state != readyToGame)
	{
		throw std::exception
			("in slotMachine::startGame: not ready to game");
	}
	//вращаем барабан
	int time = rand() % 10 + 10;
	for (int i = 0; i < time;i++)
	{
		system("cls");
		temp_drum=drum.show();
		Sleep(500);
		
	}
	if ((temp_drum[0] == temp_drum[1]) && (temp_drum[0] == temp_drum[2]))
	{
		if (temp_drum[0] == 25)
		{
			win = this->bet /2;
		}
		else if (temp_drum[0] == 26)
		{
			win = this->bet ;
		}
		else if (temp_drum[0] == 27)
		{
			win = this->bet *2;
		}
		else if (temp_drum[0] == 28)
		{
			win = this->bet *3;
		}
		else 
		{
			win = this->bet *4;
		}	
	}
	else if ((temp_drum[0] == temp_drum[1]) || (temp_drum[1] == temp_drum[2]) || (temp_drum[0] == temp_drum[2]))
	{
		win = this->bet * 2;
	}
	state = readyResult;
}