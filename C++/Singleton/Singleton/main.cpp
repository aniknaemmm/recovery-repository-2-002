#include <iostream>
#include "Settings.h"

int main()
{
	std::cout << "hello " << Settings::getInstance().name;
	Settings::getInstance().name="mohp";
	getc(stdin);
	return 0;
}