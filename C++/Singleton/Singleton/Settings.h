#pragma once
#include <string>
#include <fstream>
#include <stdexcept>
class Settings
{
private:
	Settings()
	{
			std::ifstream fin("data.txt");
			if (fin){
				fin >> name;
				fin.close();
			}
			else{
				name = "user";
			}
	}
	static Settings instatnce;

public:

	std::string name;
	static Settings& getInstance(){	return instatnce;}
	
	~Settings(){
		std::ofstream fout("data.txt");
		fout << this->name;
		fout.close();
	}
};

