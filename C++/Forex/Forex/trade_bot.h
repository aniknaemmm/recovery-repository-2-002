#pragma once
#include "Buddy.h"
#include <queue>

class trade_bot :
	public Buddy
{
private:
	double USD, EUR;
	std::queue<double> statisticSell,statisticBuy;
public:
	trade_bot() :Buddy(stock), USD(1000000), EUR(0)
	{
		statisticSell.push(stock.getSellRate());
		statisticBuy.push (stock.getBuyRate() );
	}
	virtual void act();
};

