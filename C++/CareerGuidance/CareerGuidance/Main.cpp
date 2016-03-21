#include <iostream>
#include <conio.h>
#include "Test.h"
#include <string>
#include "Trait.h"



using namespace std;

int main()
{
	Trait::Init();
	Profession::Init();
    string ratee = "Irina";
    Test test(ratee);
	while (!test.IsFinished())
		test.AskQuestion();
    test.ShowResult();
	_getch();
	getc(stdin);
	return 0;
}