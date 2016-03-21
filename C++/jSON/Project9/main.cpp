#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <iterator>
#include <ctime>
#include <string>
#include <sstream>
#include "Value.h"
#include "Scale.h"
using namespace std;

//void bubbleSort( forward_iterator_tag& from,forward_iterator_tag& to);
template<class type>
string toJSON(list<type>& obj);
int main()
{
	vector<Value*> temp_Value(3);
	//temp_Value.push_back(new Scale(5));
	srand(time(NULL));
	list<int>   temp_list;
	vector<int> temp_vect;

	for (int i = 0; i < 100; i++)
	{
		temp_list.push_back(rand() % 1000 + 1);
		temp_vect.push_back(rand() % 1000 + 1);
	}
	auto from_list = temp_list.begin();
	auto to_list = temp_list.end();

	
	{
	
		
		for (auto it = --to_list; it != from_list; it--)
		{
			for (auto ti = from_list; ti != it; ti++)
			{
				auto temp = ti;
				temp++;
				if (*ti > *temp)
				{
					auto swap = *ti;
					*ti = *temp;
					*temp = swap;
				}
			}
		}
	}

	cout << toJSON(temp_list);
	getc(stdin);
	return 0;
}

template<class type>
string toJSON(list<type>& obj)
{
	stringstream temp;
	temp << '[';
	int i = 0;
	for (auto it = obj.begin(); it != obj.end(); it++)
	{
		if (it!=obj.begin())
			temp << ',';
		temp << *it;
	}
	string str(temp.str());
	str += ']';
	return str;
}
