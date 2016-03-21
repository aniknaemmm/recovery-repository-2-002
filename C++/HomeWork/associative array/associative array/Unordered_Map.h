#pragma once

#include <iostream>
#include <list>

using namespace std;

template <class Tkey, class Tvalue>
class Unordered_map {
private:
	struct pair {
		pair(Tkey k, Tvalue v) : key(k), value(v) {};
		Tkey key;
		Tvalue value;
	};
		
public:
	list<pair> pairs;
	size_t element;

	Unordered_map():element(0) {};
	~Unordered_map() {};

	Tvalue& operator[](const Tkey key) {
		for (auto i = pairs.begin(); i != pairs.end(); ++i) {
			if (key == i->key)
				return i->value;
		}
		element++;
		pairs.push_back(pair(key, Tvalue()));
		return pairs.back().value;
	}

	void show() 
	{
		for (auto pair : pairs) 
		{
			cout << pair.key << ' ' << pair.value << endl;
		}
	}


};