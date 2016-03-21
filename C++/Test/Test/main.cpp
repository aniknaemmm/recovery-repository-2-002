#include <iostream>
#include "Test.h"
#include "Trait.h"
using namespace std;

int main()
{
Trait::init("Trait.csv");

Trait::show();
	string username;
	cout << "Enter your name:";
	cin >> username; // getline 
	if (username == "") { //?
		cout << "Enter your name:";
		cin >> username;
	}

	Test T(username);
	while (!T.finished())	{
//		T.ask();
	}

//	T.show_result();

	getc(stdin);

	return 0;
}
