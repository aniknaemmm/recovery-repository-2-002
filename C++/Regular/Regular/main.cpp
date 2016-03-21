#include <iostream>
#include <string>
#include <regex>
#include <string>
#include <istream>
#include <fstream>

int main()
{
	//std::string s("123 this subject has a -23.5 submarine as a subsequence");
	//std::smatch m;
	//
	//std::regex e("\\b\\d+([,.]\\d+)?\\b");   // matches words beginning by "sub"

	//while (std::regex_search(s, m, e)) {
	//	for (auto x : m) std::cout << x << " ";
	//	std::cout << std::endl;
	//	s = m.suffix().str();
	//}

	//std::cout << std::endl;

	//std::string s("this subject has a 23.5 submarine as a subsequence 192.168.0.1");
	//std::smatch m;
	//std::regex e("(\\d{1,3}[.]){3}\\d{1,3}");   // matches words beginning by "sub"

	//while (std::regex_search(s, m, e)) {
	//	for (auto x : m) std::cout << x << " ";
	//	std::cout << std::endl;
	//	s = m.suffix().str();
	//}

	//std::cout << std::endl;

	//std::string s("this subject has a 23.5 submarine as a subsequence united.192-gdfh@mail.ru.ru ");
	//std::smatch m;
	//std::regex e("([\\w+_-]+\\.)*[\\w+_-]+@[\\w+_-]+(\\.[\\w+_-]+)*\\.[a-z]{2,6}");   // matches words beginning by "sub"

	//while (std::regex_search(s, m, e)) {
	//	for (auto x : m) std::cout << x << " ";
	//	std::cout << std::endl;
	//	s = m.suffix().str();
	//}
	int count = 0;
	std::string buff; 
	std::ifstream fin("Professions.csv");
	if (!fin.is_open()) 
		throw std::exception("File not found");

	do{
		std::getline(fin, buff); 
		
		if (std::regex_match(buff, std::regex("\\d+[;]([\\w+-])*[;](\\d+[;]){2,4}")))
			std::cout << count << " string literal matched"  << "\n";
		else
			std::cout << count << " string literal no matched" << "\n";
		/*
		std::string s;
		std::smatch m;
		std::regex e("\\d+[;]([\\w+-])*[;](\\d+[;]){2,4}");   // matches words beginning by "sub"

		while (std::regex_search(buff, m, e)) {
			for (auto x : m) std::cout << x << " ";
			std::cout << std::endl;
			buff = m.suffix().str();
		}*/


		count++;
	} while (!fin.eof());
	fin.close(); 




	getc(stdin);
	return 0;
}