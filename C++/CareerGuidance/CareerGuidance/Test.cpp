#include "Test.h"
#include <vector>
#include <fstream>
#include <string>
#include "Question.h"
#include <sstream>
#include "ParseCSVString.h"
#include "Profession.h"
#include "Trait.h"
#include <iostream>
#include <map>
#include "Answer.h"
#include <algorithm>

// ????????????????????????????
std::vector<Question> Test::questions;


// ????????????????????????????

void Test::LoadQuestions()
{
    // check
    if (questions.size())
        return;

	std::string buffer, number;
	std::ifstream file;
	file.open("../Data/Questions.csv");
	if (!file.is_open())
		throw std::exception("Error: file(Question.csv) is not opened!\n");
	int counter = 0, question_num;

	while (!file.eof())
	{
		std::getline(file, buffer);
		std::vector<std::string> data = ParseCSVString(buffer);
        if (!data.size())
            break;
	
		number = data[0];
		std::stringstream ss(number);
		ss >> question_num;
		if (counter == question_num)
		{
			Question q(data[1]);
			questions.push_back(q);
			counter++;
		}
		else
		{
			file.close();
			throw std::exception("Error: file(Question.csv) content!\n");
		}
	}
	file.close();

}






void Test::LoadAnswers()
{
	std::string buffer, number;
	std::ifstream file;

	file.open("../Data/Answers.csv");
	if (!file.is_open())
		throw std::exception("Error: file(Question.csv) is not opened!\n");

	int question_num;
	while (!file.eof())
	{
		std::getline(file, buffer);
		std::vector<std::string> data = ParseCSVString(buffer);
		if (!data.size())
			break;

		number = data[0];
		std::stringstream ss(number);
		ss >> question_num;

		Answer answer(data[1]);
		for (auto it = data.begin() + 2; it != data.end(); it++)
		{
			// read trait number
			int trait_, score_;
			number = *it;
			std::stringstream ss1(number);
			ss1 >> trait_;

			//read score
			it++;

			number = *it;
			std::stringstream ss2(number);
			ss2 >> score_;
			answer.AddPoint(trait_, score_);
		}
		questions[question_num].answers.push_back(answer);
	}
	file.close();
}

bool IsNumeric(const string p)
{
	for (int i=0; i<p.length(); i++)
	if (p[i] < '0' || p[i] > '9')
		return false;
	return true;
}



void Test::AskQuestion()
{
    // ASK QUESTION

    std::cout << questions[current_question].question << std::endl;
    // output annswer options for this question
    int answer_num = 1;
    for (auto it = questions[current_question].answers.begin();
		it != questions[current_question].answers.end(); it++, answer_num++)
        std::cout << answer_num << it->answer << std::endl;
    // processing answer
    int ratee_response;
	std::string str;
    do
    {
		std::getline(std::cin, str);
		ratee_response = atoi(str.c_str());;
        if (ratee_response < 1 || ratee_response > answer_num - 1|| !IsNumeric(str)) 
            std::cout << "You enter invalid number! Try again!\n" ;
	} while (ratee_response < 1 || ratee_response > answer_num - 1 || !IsNumeric(str));


    // PROCESSING RESULT

    auto points = ((questions[current_question]).answers)[ratee_response - 1].points;
    
	for (auto it = points.begin(); it != points.end(); it++)
        human.result[it->first] += it->second;
    current_question++;
}


void Test::ShowResult()
{
	int prof_number = 0;
	for (auto it = Profession::professions.begin(); it != Profession::professions.end(); it++, prof_number++)
	{	
		// ????????????????????????????????????????
		human.final_result[prof_number] = 0;
		for (auto trait = it->traits.begin(); trait != it->traits.end(); trait++)
			human.final_result[prof_number] += human.result[*trait];
	}

	struct prof_value
	{
		trait_numb trait;
		int value;
		prof_value(trait_numb trait_, int value_) :trait(trait_),value(value_){};
	};

	vector<prof_value> prof_vector;
	   
    for (auto &fr: human.final_result)
    {
		prof_vector.push_back(prof_value(fr.first, fr.second));
    }

	std::sort(prof_vector.begin(), prof_vector.end(), [](const prof_value &i, const prof_value &j){return i.value > j.value; });

	
    for(auto it : prof_vector)
    {
        
            std::cout << Profession::professions[it.trait].name <<"--"<<it.value<<std::endl;    
    }

}
