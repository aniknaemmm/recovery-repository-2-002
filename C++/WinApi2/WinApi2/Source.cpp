#include <algorithm>
#include <vector>
#include <iostream>
#include <tchar.h>
#include <Windows.h>
#include <fstream>
#include <string>

#include <locale>
#include <codecvt>

using namespace std;

struct Man
{
	Man(string lastname_, string firstname_) :lastname(lastname_), firstname(firstname_){};
	string lastname, firstname;
};

int wmain() {
	wcout.imbue(locale(".866"));
	vector<Man> people;
	wifstream fin("s.txt");
	wstring buf,buflastn,buffirstn;
	fin.imbue(std::locale(fin.getloc(),	new std::codecvt_utf16<wchar_t, 0x10ffff, std::consume_header>));
		
	while (!fin.eof())
	{
		
		getline(fin,buf);
	
		std::wstring::size_type pos = buf.find(' ');
		buflastn.insert(pos,);
	
		wcout << buf<<"\n";
	}

	

	getc(stdin);
}