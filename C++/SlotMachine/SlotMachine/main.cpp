#include "Player.h"
#include "SlotMachine.h"
#include "Drum.h"
#include <iostream>
#include <Windows.h>
int main(){

	Drum Gosha(30,5);
	Player Ignat(100);
	SlotMachine M(1000,30,3);
	char ans;
	do {
		Ignat.play(M, 10);
		std::cout << Ignat.toString() << "\n" << M.toString() << std::endl;
		std::cout << "play? (y/n)" << std::endl;
		std::cin >> ans;
	} while (ans== 'y');

	
	std::getc(stdin);
	return 0;
}