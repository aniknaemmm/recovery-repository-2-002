#pragma once
#include <ratio>
#include <chrono>
#include <list>
#include <map>
#include <vector>
#include <fstream>
#include "../../HomeWork/associative array/associative array/Ordered_Map.h"

using namespace std;

void pushList  (int* arr, int size, ofstream &fs);
void pushVector(int* arr, int size, ofstream &fs);
void pushMap   (int* arr, int size, ofstream &fs);
void pushHash  (int* arr, int size, ofstream &fs);
_int64 SortVector(vector<int> temp);
_int64 SortList  (list<int>   &temp);
_int64 selectMap    (map<int, int>         &temp, int size);
_int64 selectHash   (ordered_map<int, int> &temp, int size);