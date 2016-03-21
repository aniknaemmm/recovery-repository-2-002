#pragma once
#include <string>
#include <map>



typedef size_t trait_numb;

// ...
class Answer
{
public:
	std::string answer;

    //trait_num - it's index number of trait, int - trait's score
	std::map<trait_numb, int> points;

    Answer(std::string answer_): answer(answer_) {}
    void AddPoint(trait_numb trait_, int score_) { points[trait_] = score_; }

};





