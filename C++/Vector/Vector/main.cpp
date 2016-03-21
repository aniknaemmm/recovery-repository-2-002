#include "Vector.h"
#include "Sort.h"
#include <new>
#include <iostream>
#include <conio.h>
#include <new>
#include <stdio.h>

using namespace std;
int main()
{
	Vector<int> a_int;

	for (int i = 0; i < 7; i++)
		a_int.pushFront(i);
	
	auto p = a_int.find(1);
	if (p == a_int.end()) {
		cout << "value not found!\n";
		return 0;
	}
	sort(a_int.begin(),a_int.end());
	//a_int.erase(p);
	
	for (auto q = a_int.begin(); q != a_int.end(); ++q) {
		cout << *q << endl;
	}
	getc(stdin);


	return 0;

}
/*#include <iostream>
#include <stdio.h>

int main()
{/*
	Vector<int> a(15);
	Vector<int> b(2);
	Vector<int> c;
	a.pushFront(4);
	a.pushBack(3);
	a.pushFront(5);
	auto p = a.find(3);
	if (p != a.end()){
		std::cout << 322323233<<std::endl;
	}
	std::cout << a.getValue(1);
	std::cout << a.getValue(2);
	std::cout << a.getValue(3)<<std::endl;
	a[1] = 99;
	std::cout << a.popBack();
	std::cout << a.popFront();
	std::cout << a.popFront();
	//a[0] = 12;

	Vector b,c;

	b....


	c = a+b;

	ofstream fs("x.txt");

	fs << a;

	fs.close();
	
	
	getc(stdin);


	return 0;
}*/