#include "Func.h"
#include <list>
#include <vector>
#include <map>
#include <cstdlib>
#include <algorithm> 
#include "../../HomeWork/associative array/associative array/Ordered_Map.h"

using namespace std::chrono;
using namespace std;

void pushList(int* arr, int size,ofstream &fs)
{
	list<int> tempList;
	system_clock::time_point start = system_clock::now();
	for (int i = 0; i < size; i++)
			tempList.push_back(arr[i]);
	system_clock::time_point end = system_clock::now();
	milliseconds result = duration_cast<milliseconds> (end - start);
	fs << ";" << result.count() << " ";
	cout << "List  push=" << result.count();
	int r = SortList(tempList);
	fs << ";" << r << " ";
	cout << "  sort=" << r << endl;
}



void pushVector(int* arr, int size, ofstream &fs)
{
	vector<int> tempVector;
	system_clock::time_point start = system_clock::now();
	for (int i = 0; i < size; i++)
		tempVector.push_back(arr[i]);
	system_clock::time_point end = system_clock::now();
	milliseconds result = duration_cast<milliseconds> (end - start);
	fs << ";" << result.count() << " ";
	cout << "Vector push=" << result.count();
	int r = SortVector(tempVector);
	fs << ";" << r << " ";
	cout << "  sort=" << r << endl;
	
}


void pushMap(int* arr, int size, ofstream &fs)
{
	map<int,int> tempTree;
	system_clock::time_point start = system_clock::now();
	for (int i = 0; i < size; i++)
		tempTree[i] = arr[i];
	system_clock::time_point end = system_clock::now();
	milliseconds result = duration_cast<milliseconds>  (end - start);
	fs << ";" << result.count() << " ";
	cout << "Map push=" << result.count();
	int r = selectMap(tempTree,size);
	fs << ";" << r << " ";
	cout << "  select=" << r << endl;
}

void pushHash(int* arr, int size, ofstream &fs)
{
	ordered_map<int, int> tempHash(size);
	system_clock::time_point start = system_clock::now();
	for (int i = 0; i < size; i++)
		tempHash[i] = arr[i];
	system_clock::time_point end = system_clock::now();
	milliseconds result = duration_cast<milliseconds>  (end - start);
	fs << ";" << result.count() << " ";
	cout << "Hash  push=" << result.count();
	int r = selectHash(tempHash,size);
	fs << ";" << r << " ";
	cout << "  select=" << r << endl;
}


_int64 SortVector(vector<int> temp)
{
	system_clock::time_point start = system_clock::now();
	sort(temp.begin(),temp.end());
	system_clock::time_point end = system_clock::now();
	milliseconds result = duration_cast<milliseconds> (end - start);
	return result.count();
}

_int64 SortList(list<int> &temp)
{
	system_clock::time_point start= system_clock::now();
	temp.sort();
	system_clock::time_point end = system_clock::now();
	milliseconds result = duration_cast<milliseconds> (end - start);
	return result.count();
}


_int64 selectMap(map<int, int> &temp, int element)
{
	system_clock::time_point start = system_clock::now();
	for (int i = 0; i < element; i++)
		temp.find(i);
	system_clock::time_point end = system_clock::now();
	milliseconds result = duration_cast<milliseconds> (end - start);
	return result.count();
}
_int64 selectHash(ordered_map<int, int> &temp, int size)
{
	system_clock::time_point start = system_clock::now();
		for (int i = 0; i < size; i++)
			temp[i];
	system_clock::time_point end = system_clock::now();
	milliseconds result = duration_cast<milliseconds> ( end- start);

	return result.count();
}