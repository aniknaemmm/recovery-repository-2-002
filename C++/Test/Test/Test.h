#pragma once
#include "Ratee.h"
#include "Question.h"
#include <vector>

// тест, проходимый конкретным испытуемым
class Test
{
public:

	// объект-испытуемый
	Ratee r;
	// список вопросов теста
	static std::vector<Question> questions;
	// итератор на текущий вопрос, который будет задан
	std::vector<Question>::iterator current_question;
	// задать очередной вопрос
	//void ask();
	// если все вопросы отвечены, то показать результат теста
	//void show_result();
	static void read_questions();
	bool finished() {	return current_question == questions.end();}

	Test(std::string& name_) : r(name_), current_question(questions.begin()) {

	};
};
