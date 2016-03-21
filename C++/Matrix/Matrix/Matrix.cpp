#include "Matrix.h"
#include <vector>
#include <iostream>
const Matrix<double> Matrix<double>::zero(3, 3 , 0);
const Matrix<double> Matrix<double>::unit(3, std::vector<double>(3, 1));

int main()
{
	std::vector<std::vector<double>>q{ { 0, 0, 0 }, { 1, 0, 0 }, { 1, 1, 0 }, { 0, 1, 0 } };
	auto r = Matrix<double>::rotateY(0.5);
	while (1) {

		for (auto it = q.begin(); it != q.end(); it++) {
			auto &v = (*it);
			v = r*v;
			for (auto coord : v) {
				std::cout << " " << coord;


			}
			std::cout << "\n ---- \n";

		}
		std::cout << "\n ---------------------- \n";
		for (int i = 0; i < 100000000; i++);
	}
	getc(stdin);
	return 0;
}