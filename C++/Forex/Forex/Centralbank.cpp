#include "Centralbank.h"
#include <cmath>

void CentralBank::act() {

	volatility.push((stock.getSellRate() * stock.getBuyRate())/2);

	if (volatility.size() > 5) 
	{
		volatility.pop();
		double rate = volatility.back() / volatility.front();
		if (rate > 1.1)
			stock.makeSellBet(stock.getSellRate(), pow(10, 6));
		else if (rate < 0.9)
			stock.makeBuyBet (stock.getBuyRate() , pow(10, 6));
	}

}