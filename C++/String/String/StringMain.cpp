#include "String.h"
#include <iostream>


int main(){
	
	/*
	b.FirstNChar(2, c);
	c.PrintStr();
	b.EndNChar(3, c);
	c.PrintStr();
	


	b.Substr(3, 2, c);
	c.PrintStr();

	b.DeleteSpace(c);
	*/
	

	//b = a; //присваивание
	/*
	b.UpReg();
	b.PrintStr();
	*/
	//c = b.PlusNewStr(a);
	//c.PrintStr();

	/*
	b.Plus(" world!");

	a.PrintStr();

	if (b.Find("lo")){
		std::cout << "lo is found in Hello!" << std::endl;
	}


	b.PrintStr();
	*/
	String  a("a"), b("b"), c("c"), d;
	d = a + b + c;
	PrintStr(d);
	std::getc(stdin);
	return 0;
}