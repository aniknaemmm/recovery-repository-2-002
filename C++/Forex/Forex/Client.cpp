#include "Client.h"
#include <math.h>

void Client::act() 
{
	double amount = 0;

	if ((stock.getSellRate() / stock.getBuyRate()) < 1.0001) 
		amount = pow(10, (rand() * 6.0) / RAND_MAX);
	else 
		amount = pow(10, (rand() * 5.0) / RAND_MAX);
	
	if (!(rand() % 2))
		stock.buy(amount);
	else 
		stock.sell(amount);
	
}