#pragma once

#include <map>

class Stock
{
private:
	std::map<double, double> sellBets, buyBets;

public:

	Stock(){};
	~Stock(){};

	double getSellRate() const 
	{
		if (!sellBets.size())
			return 2.0;
		return sellBets.begin()->first;
	}

	double getBuyRate() const 
	{
		if (!buyBets.size())
			return 1.1;
		return buyBets.rbegin()->first;
	}

	void makeSellBet(const double rate, double amount);
	void makeBuyBet (const double rate, double amount);
	void buy (double amount);
	void sell(double amount);
	
};
