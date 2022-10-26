#include <string>
#include "choices.hpp"

using std::string;

class Question {

protected:
	string category;
	string type;
 	string difficulty;
 	string question;
 	string correct_answer;
 	string *incorrect_answers;
 	int number_incorrect_answers;
	

public:
  Question(string file_name, int index);
  ~Question();
  virtual int print_question();

};