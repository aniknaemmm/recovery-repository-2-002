#include "Player.h"
#include <math.h>

void Player::act() {

	double amount = pow(10, (rand() * 5.0) / RAND_MAX);
	double drate  = ((double(rand()) / RAND_MAX) - 0.5) * (stock.getSellRate() - stock.getBuyRate());

	int choise = rand() % 2;
	if (!choise) 
		stock.makeSellBet (drate + stock.getSellRate(), amount);
	else 
		stock.makeBuyBet  (drate + stock.getBuyRate(),  amount);
	
}