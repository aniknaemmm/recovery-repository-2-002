#pragma once
#include <vector>
#include <Windows.h>
#include <initializer_list>
#include <exception>
#include "../../Matrix/Matrix/Matrix.h"

class Cube
{
private:
	std::vector<double>  startVector, endVector;
public:
	static HDC hdc;
	Cube(std::initializer_list<double> list1, std::initializer_list<double> list2)
	{
		
		auto it1=list1.begin(), it2=list2.begin(); 
		for (int i = 0; i < 3;i++,it1++,it2++)
		{
			startVector.push_back(*it1);
			endVector.push_back(*it2);
		}
	}

	Cube& operator*=( Matrix<double>& temp)
	{
		startVector = temp* startVector ;
		endVector = temp* endVector;
		return *this;
	}

	void show()
	{
		Matrix<double> mat(2, 3, { 1, 0, 0.7, 0, 1, 0.7 });
		std::vector<double> v1 = mat*startVector, v2 =  mat*endVector;
		MoveToEx(hdc, v1[0]+200, v1[1]+200, NULL);
		LineTo(hdc, v2[0]+200, v2[1]+200);
	}
	
};

