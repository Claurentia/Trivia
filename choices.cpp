#include <string>
#include <iostream>
#include <vector>
#include "choices.hpp"

using std::cout;
using std::endl;
using std::string;

// constructor: fill in a vector of possible answer
Choices::Choices(string correct, string *incorrect, int size) {
	
	for (int i = 0; i < size; i++) {
	  string choice = incorrect[i];
		choices.push_back(choice);
	}
	choices.push_back(correct);
	correct_choice = correct;
	
	Choices::size = choices.size();

}

Choices::~Choices(){		
}

// return true if the chosen number is the correct answer
bool Choices::correct(int *arr) {
	for (int i = 0; i < size; i++) {
		if (arr[i] != 0) {
			return false;
		}
	}
	return true;
}

// prompt user for answer
bool Choices::choose(int *arr) {
	int ans = 0;

	cout << "\t\tWhich number to choose? > ";
	std::cin >> ans;

	while (ans < 1 || ans > size) {
		cout << "\t\tInvalid input, try again > ";
		std::cin >> ans;
	}

	arr[ans - 1] -= 1;
	
	return correct(arr);
	
}


// print possible choices in random order and call choose method to prompt user choice
bool Choices::print_choices() {
	
	int arr[size]; 		 // to track where the correct answer lies
	int tracker[size]; // to track if the choice already printed out
	
	for (int i = 0; i < size; i++) {
		arr[i] = -1;
		tracker[i] = -1;
	}
	
	for (int i = 0; i < size; i++) {
	 	cout << "\t" << (i + 1) << ") ";

		srand(time(NULL));
	 	int ind;
	 	string c;
		
	 	do {
	 		ind = rand() % size;
	 		c = choices[ind];
			
	 	} while(arr[ind] != -1);

	 	cout << c << endl;

	 	if (c == correct_choice) {
	 		arr[ind] = 1;
			tracker[i] = 1;
	 	} else {
	 		arr[ind] = 0;
			tracker[i] = 0;
	 	}
	}

	bool val = choose(tracker);
	
	if (val) {
		cout << "\t\t\tCorrect, keep it on!" << endl;
	} else {
		cout << "\t\t\tIncorrect! The answer is " << correct_choice << endl;
	}
	
	return val;
	
}