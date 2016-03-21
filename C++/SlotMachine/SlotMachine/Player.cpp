#include "Player.h"
#include "SlotMachine.h"
#include <iostream>
#include <string>
#include <sstream>

void Player::play(SlotMachine& machine, unsigned int bet)
{
	try{
		//����� ������ �������
		// TODO: check money may be player not mony
		this->sum -= bet;
		//������� ������ � �������
		machine.makeBet(bet);
		//����� ��������� ������� � ���� ���������
		machine.startGame();
		//����� �������� ������� , ���� �� ���� 
		this->sum += machine.getMoney();
	}
	catch (std::exception e) {
		std::cerr << e.what() << std::endl;
	}
};

std::string Player::toString(){

	std::stringstream sum;
	sum << this->sum;
	return sum.str();
}

void Player::Win(unsigned int money){
	this->sum += money;
}


