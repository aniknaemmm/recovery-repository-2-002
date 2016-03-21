#include "Stock.h"
#include "Buddy.h"
#include "Player.h"
#include "Client.h"
#include "Centralbank.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>


using namespace std;

int main() {

	srand(time(nullptr));
	ofstream fs("stock.csv");
	fs.imbue(locale("")); // использовать региональные настройки по умолчанию

	Stock stock;
	CentralBank bank(stock);
	vector<Buddy*> buddies{ new Player(stock), new Player(stock), new Player(stock), new Client(stock), new Client(stock) };
	stock.makeBuyBet ( 1.0  , 1e9);
	stock.makeSellBet( 1.8  , 1e9);
	stock.makeBuyBet ( 1.24 , 1e5);
	stock.makeSellBet( 1.26 , 1e5);
	stock.makeBuyBet ( 1.25 , 1e7);
	stock.makeSellBet( 1.27 , 1e7);

	
	fs << "time;buy rate;sell rate\n";
	for (int i = 1; i <= 10000; ++i)
	{
		for (auto it = buddies.begin(); it != buddies.end(); ++it) 
			(*it)->act();
		
		if (i % 5 == 0)
			bank.act();
		if (!(i%100))
		fs << i << ";" << stock.getBuyRate() << ";" << stock.getSellRate() << "\n";
	}

	fs.close();

	cout << "End"<<endl;
	getc(stdin);
	return 0;
}