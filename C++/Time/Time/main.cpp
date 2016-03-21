#include <ctime>
#include "Func.h"
#include <random>
#include <iostream>
#include <fstream>

using namespace std;
const int N = 0x100000; 

int main()
{
	srand(time(nullptr));
	int *arr = new int[N];
	for (size_t i = 0; i <= N; ++i) 
		arr[i] = rand();
	

	ofstream fs("../qwer.txt");
	fs << "element ; list push;list sort;vector push ; vector sort ; map push; map select ; hash push ; hash select ;" << endl;
	for (int NN = 0x1000; NN <= N; NN *= 2)
	{
		cout << NN << " elements " << endl;
		fs << NN ;
		pushList   (arr , NN , fs);
		pushVector (arr , NN , fs);
		pushMap    (arr , NN , fs);
		pushHash   (arr , NN , fs);
		fs << endl;
	}
	fs.close();

	cout << "end" << endl;
	getc(stdin);
	return 0;
}