#pragma once
#include <vector>
#include "Question.h"
#include "Ratee.h"
#include "Profession.h"
#include <string>
#include "Trait.h"



class Test
{
private:
	Ratee human;
    int current_question;
	//std::vector<Question>::iterator current_question;
	static void LoadQuestions();
	
	
	static void LoadAnswers();

public:
    //container of questions and answers
	static std::vector<Question> questions;
    
    




    Test(std::string &name): human(name), current_question(0) {
		LoadQuestions(), LoadAnswers(); }
    

	bool IsFinished(){ return current_question == questions.size(); }

	

	//when we ask ratee
	void AskQuestion();
	//shows ratee's results of test
	void ShowResult();

};



