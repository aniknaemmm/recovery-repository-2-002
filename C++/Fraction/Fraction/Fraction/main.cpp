#include "Fraction.h"
#include <iostream>
#include <stdio.h>
#include <cstdbool>

using namespace std;
int main()
{	
	std::cout << "Hello World!!"<<std::endl ;
	
	Fraction a;
	Fraction g(2,3);
	Fraction c(3,2);
	Fraction b(3,2);
	
	c =g-b ;
	cout << c.numerator<<"/"<<c.denumenator<<endl;
	if (g < b)
		cout << "1";
	else
		cout << "0";
	getc(stdin);
	return 0;
}