#pragma once

#include "Buddy.h"
#include "Stock.h"
#include <queue>

class CentralBank : public Buddy {
private:
	std::queue<double> volatility;
public:
	CentralBank(Stock& stock) : Buddy(stock) { volatility.push((stock.getSellRate() * stock.getBuyRate())/2); };
	~CentralBank() {};

	virtual void act();
};

