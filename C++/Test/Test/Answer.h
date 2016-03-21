#pragma once

#include "trait.h"
#include <vector>
#include <string>
#include <map>

using std::string;
using std::map;
using std::vector;

class answer {
private:
	//contains text of the answer
	const string text;
	//contains container of pairs (size_t - it's index number of trait, int - trait's score)
	map<size_t, int> points;

public:
	//structure that contains size_t and int fields (and have its own ctor)
	struct point {
		size_t num;
		int score;

		point(const size_t& num_, const int& score_) : num(num_), score(score_) {};
	};

	//ctors
	answer(const string& text_) : text(text_) {};

	answer(const string& text_, vector<point> list) : text(text_) {
		for (auto it = list.begin(); it != list.end(); ++it) {
			points[it->num] = it->score;
		}
	}

	//methods

	//pushes pair of values (size_t, int) to map
	void push(const point& point_) {
		points[point_.num] = point_.score;
	}
};