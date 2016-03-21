#include <cmath>
#include <vector>
#include <algorithm>
#include <numeric>      // std::accumulate
#include <string>
#include <sstream>
#include <iostream>

int main()
{
	int series = 1000;

	std::cout << ([&series](){return series; })() << "\n";
	std::vector<int> arr = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 15, 16, 17 };
	std::vector<int> prim{ 2, 3, 5 };
	int mycount = 0;
	mycount = std::accumulate(arr.begin(), arr.end(), mycount, [&prim](int i, int j) {
	//	if (std::count_if(prim.begin(), prim.end(), [j](int k) { return (((k % j) == 0)) && k != j; })){ return i; } return i + j;
	});

	std::cout << mycount << std::endl;

	int sum = 0;
	sum = std::count_if(arr.begin(), arr.end(), [](int i, int j) { return i + j; });
	std::cout << sum << std::endl;

	std::string s;
	s = std::accumulate(arr.begin(), arr.end(), s, [](std::string i, int j) {i += std::to_string(j); return i += ';'; });
	std::cout << s << std::endl;

	int temp = 0;
	std::vector<int> my_vec;
	int k = 0;
	k = std::accumulate(arr.begin(), arr.end(), k, [&temp, &my_vec](int i, int j) { if (abs(j - temp) > 1) my_vec.push_back(j); temp = j; return 0; });
	std::for_each(my_vec.begin(), my_vec.end(), [](const int &element){std::cout << element << ';'; });

	getc(stdin);
}