#include <string>
#include <vector>

using std::string;

class Choices {

protected:
	std::vector<string> choices;
	string correct_choice;
	int size;

public:
  Choices(string correct, string *incorrect, int in_size);
  ~Choices();
	bool correct(int *arr);
	bool choose(int *arr);
	bool print_choices();

};