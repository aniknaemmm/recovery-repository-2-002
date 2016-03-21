#pragma once

#include "trait.h"
#include <string>
#include <vector>
#include <initializer_list>

using std::string;
using std::vector;
using std::initializer_list;

class profession {
private:
	//name of profession
	const string& name;
	//container of requirement traits for this profession
	vector<size_t> traits;

public:
	//ctor
	profession(string name_, initializer_list<size_t> list);
};