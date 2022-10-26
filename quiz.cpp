#include<string>
#include<iostream>
#include<fstream>
#include<vector>
#include<nlohmann/json.hpp>
#include"quiz.hpp"

using std::cout;
using std::endl;
using std::string;
using std::ifstream;

Quiz::Quiz(string file_name) {
	ifstream in_stream2;
	in_stream2.open(file_name);
	nlohmann::json j;
	in_stream2 >> j;
	
	quiz_num = j["results"].size();
	for (int i = 0; i < quiz_num; i++) {
		Question *q = new Question(file_name, i);
		questions.push_back(q);
	}

}

Quiz::~Quiz(){	
	for (int i = 0; i < quiz_num; i++) {
		delete questions[i];
	}
}

int Quiz::print_all_questions() {
	int score = 0;
	for (int i; i < quiz_num; i++) {
	  score += questions[i]->print_question();
		cout << endl;
	}
	return score;
}
