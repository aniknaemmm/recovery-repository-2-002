#include "trade_bot.h"

void trade_bot::act()
{
	statisticBuy.push(stock.getBuyRate());
	statisticSell.push(stock.getSellRate());

	if (statisticBuy.size() > 5) {
		statisticBuy.pop();
		statisticSell.pop();
	
	}
}