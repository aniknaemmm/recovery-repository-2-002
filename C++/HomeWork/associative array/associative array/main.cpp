#include <iostream>
#include <cstdio>
#include "ordered_map.h"
#include <string>
#define NN 10

int main() {
	ordered_map<string, float> people(NN);
	char temp[10];

	for (int i = 0; i < NN; i++)
	{
		sprintf_s(temp, "%s%d", "AnnaZ", i);
		people[temp] = i*1.7f;
		sprintf_s(temp, "%s%d", "AlexZ", i);
		people[temp] = i*2.7f;
		sprintf_s(temp, "%s%d", "Boreau", i);
		people[temp] = i*3.7f;
	}

	//show all Hasm Map
	people.show();
	
	try{
		//search function
		cout <<"Boreau element 6:"<< people.search(6 * 3.7f) << endl;
		string ttemp = people.search(4 * 3.7f);
		cout << "Boreau element 4:"<< ttemp << endl;
		people.dell("Boreau3");
		people.show();
		cout << people.statistics() << "(" << ((double)people.statistics() / (NN*3)) * 100 << "%) colisions" << endl;
	}
	catch (exception e) {
		cerr << e.what() << endl;
	}
	catch (...) {
		cerr << "Unknown error." << endl;
	}
	

	getc(stdin);
	return 0;
}