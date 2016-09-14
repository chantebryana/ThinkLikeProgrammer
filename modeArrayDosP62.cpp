#include <iostream>
#include <cstdlib>
using std::cin;
using std::cout;

//define junk for later 
int i;
int result = 0;
const int A_LENGTH = 19;

int main () {
	//create unsorted array of survey responses 
	int surveyResponses [A_LENGTH] = {2, 5, 9, 1, 5, 4, 7, 8, 6, 2, 10, 7, 4, 5, 6, 10, 9, 1, 1};
	//print out unsorted responses 
	cout << "Unsorted survey responses: ";
	for (i = 0; i < A_LENGTH; i++) {
		cout << surveyResponses[i] << " ";		
	}
	cout << "\n";
	return 0;
} 