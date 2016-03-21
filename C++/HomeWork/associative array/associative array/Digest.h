#pragma once

#include <string>
namespace{
	template <class T>
	int& digest(T key);

	int& digest(int key) {
		int hash, i;
		for (hash = i = 0; i < key; ++i)
		{
			hash += i;
			hash += (hash << 10);
			hash ^= (hash >> 6);
		}
		hash += (hash << 3);
		hash ^= (hash >> 11);
		hash += (hash << 15);
		return hash;
	}
}