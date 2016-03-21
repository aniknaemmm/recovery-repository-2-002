#include "Stock.h"


void Stock::makeSellBet(const double rate, double amount) 
{
	// если есть заявка на покупку у которой сумма 
	// больше текущей суммы на продажу
	while (rate <= getBuyRate()) 
	{
		// bet - итератор на самую выгодную сделку покупки
		auto bet = buyBets.rbegin();
		//если в сууществующей заявке больше денег чем в новой
		if (amount < bet->second) 
		{
			// частично осуществляем существующую заявку
			bet->second -= amount;
			// и не ставим новую
			return;
		}
		// если в существующей заявке денег не хватило
		// снимаем сущетвующую
		amount -= bet->second;
		buyBets.erase(bet->first);
		if (amount == 0) 
			// если продавать больше нечего
			return;
	}
	// если осталось, что продавать
	if (sellBets.find(rate) == sellBets.end())  
		sellBets[rate] = amount;
	else 
		sellBets[rate] += amount;
}

void Stock::sell(double amount) 
{
	while (amount > 0) 
	{
		auto bet = buyBets.rbegin();
		if (bet == buyBets.rend()) 
			return;
		if (amount < bet->second)
		{
			bet->second -= amount;
			return;
		}
		amount -= bet->second;
		buyBets.erase(bet->first);
	}
}


void Stock::makeBuyBet(double rate, double amount) 
{
	while (rate >= getSellRate()) 
	{
		auto bet = sellBets.begin();
		if (amount < bet->second) 
		{
			bet->second -= amount;
			return;
		}
		amount -= bet->second;
		sellBets.erase(bet);
		if (!amount)
			return;
	}
	if (buyBets.find(rate) == buyBets.end())
		buyBets[rate] = amount;
	else
		buyBets[rate] += amount;
}




void Stock::buy(double amount) 
{
	while (amount > 0) 
	{
		auto bet = sellBets.begin();
		if (bet == sellBets.end()) 
			return;
		
		if (amount < bet->second)
		{
			bet->second -= amount;
			return;
		}
		amount -= bet->second;
		sellBets.erase(bet->first);
	}
}
