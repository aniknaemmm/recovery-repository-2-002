/*
*1. пром работу автом с двиг внут сгорани€
*2. массив с рез обсл пациент вы€вить 3 поц с макс риском заболевани€
*
*
*/

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <numeric>      // std::accumulate
#include <string>
#include <algorithm>
#include "Pacient.h"
#include <cmath>

using namespace std;



int main()
{




	vector<Pacient> analysis{};
	analysis.push_back(Pacient("oleg", 4, 2, 3));
	analysis.push_back(Pacient("olya", 7, 3, 6));
	analysis.push_back(Pacient("ira ", 4, 2, 3));
	analysis.push_back(Pacient("ivan", 3, 5, 3));
	analysis.push_back(Pacient("tank", 9, 1, 7));
	analysis.push_back(Pacient("tank", 6, 7, 3));
	vector<Pacient> bolnie;

	for_each(analysis.begin(), analysis.end(), [&bolnie](Pacient val){	if (val.sick)  bolnie.push_back(val);} );

	 sort(bolnie.begin(), bolnie.end(), [](Pacient val1, Pacient val2)->bool
	 { 
	
		 if (val1.maxOtkl>val2.maxOtkl ) return true;
		 return false;
	 }
	 );
	 cout << "all pocient " << endl;
	 for_each(analysis.begin(), analysis.end(), [](Pacient obj)
	 {
		 cout << "Name : " << obj.name << "; krov1 : " << obj.krov1 << "; krov2 : " << obj.krov2 << "; krov3 : " << obj.krov3 << endl;
	 }
	 );
	 cout << endl << "----------------------------------------------" <<endl<< "sick" << endl;
	 int size = 3;
	 if (bolnie.size() < 3)
		 size = bolnie.size();
		 for_each(bolnie.begin(), bolnie.begin() + size, [](Pacient obj)
		 {
			 cout << "Name : " << obj.name << "; krov1 : " << obj.krov1 << "; krov2 : " << obj.krov2 << "; krov3 : " << obj.krov3 << endl;
		 }
		 );
	

	 getc(stdin);
	return 0;
}

