#pragma once
#include <string>
#include <vector>
#include <algorithm>
const static struct  Parametr
{
	int krov1Max = 7, krov1Min = 3;
	int krov2Max = 4, krov2Min = 2;
	int krov3Max = 6, krov3Min = 3;
}Parametr;

class Pacient
{
public:
	int krov1, krov2, krov3;
	int maxOtkl;
	bool sick;
	std::string name;
	Pacient(std::string name_, int krov1_, int krov2_, int krov3_) :name(name_), krov1(krov1_), krov2(krov2_), krov3(krov3_) 
	{
		maxOtkls();
		chekSick();
	};
	void maxOtkls()
	{
		int otkl1 = abs(krov1 - (Parametr.krov1Max + Parametr.krov1Min) / 2);
		int otkl2 = abs(krov2 - (Parametr.krov2Max + Parametr.krov2Min) / 2);
		int otkl3 = abs(krov3 - (Parametr.krov3Max + Parametr.krov3Min) / 2);
		int m1 = std::max(otkl1, otkl2);
		 maxOtkl = std::max(m1, otkl3);
	}

	void chekSick()
	{
		if ((krov1 > Parametr.krov1Max || krov1 < Parametr.krov1Min) ||
			(krov2 > Parametr.krov2Max || krov2 < Parametr.krov2Min) ||
			(krov3 > Parametr.krov3Max || krov3 < Parametr.krov3Min))
			sick = true;
		else sick = false;
	}
	~Pacient();
};

