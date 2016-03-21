#include "Test.h"
#include <string>
#include <fstream>
#include <sstream>
#include "Question.h"

std::vector<Question> Test::questions;

void Test::read_questions() {
	std::string buf, temp;
	std::ifstream file;
	file.open("questions.csv");
	if (!file.is_open()) {
		throw std::exception("File questions.csv: Error opening file\n");
	}
	int counter = 0, number;
	while (!file.eof()) {
		// читаем очередную строчку из файла в переменную buf
		std::getline(file, buf);
		std::stringstream ss(buf);
		// считываем число в переменную number (как scanf)
		ss >> number;
		if (counter != number) {
			throw std::exception("File questions.csv: Error file content\n");
		}
		int position = buf.find(";");
		// удаляем из строки все кроме вопроса
		auto last_pos = buf.size() - position - 1;
		temp = buf.substr(position + 1, last_pos);
		Question q(buf);
		questions.push_back(q);
		++counter;
	}
	file.close();
}

