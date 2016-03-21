#include "Trait.h"
#include <vector>
#include <fstream>
#include <exception>
#include <sstream>
#include <cstdbool>
#include <iostream>

std::vector<Trait> Trait::traits;

void Trait::show(){	
	for (size_t i = 0; i < traits.size(); ++i){
		std::cout << i << "; " << traits[i].name << std::endl;
	}
}

void Trait::init(std::string filename){	
	std::string buff; // буфер промежуточного хранения считываемого из файла текста
	std::ifstream fin(filename);
	if (!fin.is_open()) // если файл не открыт
		throw std::exception("File not found");
	
	do{
		std::getline(fin, buff); // считали строку из файла
		parse(buff);
	} while (!fin.eof());
	fin.close(); // закрываем файл
	
}

void Trait::parse(std::string buf){
	
	std::string str;
	bool f = false;
	for (size_t i = 0; i < buf.length(); i++){
		if (!f){
			if (buf[i] == ';'){
				if (i == 0 || i == buf.length()) {
					std::stringstream ss;
					ss << "Incorect format line " << buf;
					throw std::exception(ss.str().c_str());
				}
				size_t index = atoi(str.c_str());
				if (index != traits.size()){
					std::stringstream ss;
					ss << "Incorect index " << buf;
					throw std::exception(ss.str().c_str());
				}
				str.clear();
				f = true;
				continue;
			}
			str += buf[i];
		}else{
			str += buf[i];
		}
	}
	Trait *t = new Trait(str);
	traits.push_back(*t);
}
