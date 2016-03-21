#pragma once
#include <string>
#include <vector>
#include "Answer.h"



class Question
{
private:
    

public:
	std::string question;
	std::vector<Answer> answers;

    Question(std::string &str) : question(str) { }



};

