#include <new>
#include "List.h"
#include <iostream>
#include <conio.h>
#include <new>
#include <stdio.h>

using namespace std;
int main()
{
	Vector<int> a_int;

	for (int i = 0; i < 7; i++)
		a_int.PushFront(i);

	auto p = a_int.find(0);
	if (p == a_int.end()) {
		cout << "value not found!\n";
		return 0;
	}

	a_int.erase(p);

	for (List<int>::iterator q = a_int.begin(); q != a_int.end(); ++q) {
		cout << *q << endl;
	}
	getc(stdin);
	return 0;

}