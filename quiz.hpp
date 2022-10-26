#include <string>
#include <vector>
#include"question.hpp"

using std::string;

class Quiz {

	protected:
		std::vector<Question*> questions;
		int quiz_num;

public:
  Quiz(string file_name);
  ~Quiz();
	int print_all_questions();

};