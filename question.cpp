#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
#include "question.hpp"


using std::cout;
using std::endl;
using std::string;
using std::ifstream;

Question::Question(string file_name, int in) {
	ifstream in_stream2;
	in_stream2.open(file_name);
	nlohmann::json j;
	in_stream2 >> j;

	category = j["results"][in]["category"];
	type = j["results"][in]["type"];
	difficulty = j["results"][in]["difficulty"];
	question = j["results"][in]["question"];
	correct_answer = j["results"][in]["correct_answer"];

	number_incorrect_answers = j["results"][in]["incorrect_answers"].size();
		
	incorrect_answers = new string[number_incorrect_answers];
	for (int i = 0; i < number_incorrect_answers; i++) {
		incorrect_answers[i] = j["results"][in]["incorrect_answers"][i];
	}
}

Question::~Question(){		
}

int Question::print_question() {
	cout << "Category: " << category << endl;
	cout << "Type: " << type << endl;
	cout << "Difficulty: " << difficulty << endl;
	cout << "Question: " << question << endl;

	Choices *c = new Choices(correct_answer, incorrect_answers, number_incorrect_answers);

	if (c->print_choices()) {
		return 1;
	} else {
		return 0;
	}

	delete c;
	
}