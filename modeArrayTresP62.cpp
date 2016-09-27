#include <iostream>
#include <cstdlib>
using std::cin;
using std::cout;
	
//define junk for later 
int i; 
const int A_LENGTH = 19;
const int RESPONSE_LENGTH = 5;
int ones, twos, threes, fours, fives = 0;
int tallyArray [RESPONSE_LENGTH] = {};

//create unsorted array of survey responses 
//int surveyResponses [A_LENGTH] = {2, 5, 9, 1, 5, 4, 7, 8, 6, 2, 10, 7, 4, 5, 6, 10, 9, 1, 1};
int surveyResponses [A_LENGTH] = {2, 5, 4, 1, 5, 4, 2, 3, 1, 2, 5, 2, 4, 5, 1, 5, 4, 1, 1}; //simlified: 1 to 5

//define comparison function for qsort
int compareFunc(const void *voidA, const void *voidB) {
	int *intA = (int *)(voidA);
	int *intB = (int *)(voidB);
	return *intA - *intB;
}

///*
//how many of each number in survey responses?
void eachNumCount (int *array, int length) {
	for (i = 0; i < length; i++) {
		if (array[i] == 1) {
			tallyArray[0]++;
		} else if (array[i] == 2) {
			tallyArray[1] ++;
		} else if (array[i] == 3) {
			tallyArray[2] ++;
		} else if (array[i] == 4) {
			tallyArray[3] ++;
		} else if (array[i] == 5) {
			tallyArray[4] ++;
		} else {
			cout << "Unexpected error!\n";
		}
	}
}
//*/

int main () {
	//print out unsorted responses 
	cout << "Unsorted survey responses: ";
	for (i = 0; i < A_LENGTH; i++) {
		cout << surveyResponses[i] << " ";		
	}
	cout << "\n";
	//sort the unsorted responses with qsort; use compareFunc defined above 
	qsort(surveyResponses, A_LENGTH, sizeof(int), compareFunc);
	//print out sorted responses!
	cout << "  Sorted survey responses: ";
	for (i = 0; i < A_LENGTH; i++) {
		cout << surveyResponses[i] << " ";		
	}
	cout << "\n";
	//tally each response type 
	eachNumCount (surveyResponses, A_LENGTH);
	//print out tally of each response type 
	/*	
	cout << "Tally of Survey Responses:\n";
	cout << "    Ones: " << ones << "\n";
	cout << "    Twos: " << twos << "\n";
	cout << "  Threes: " << threes << "\n";
	cout << "   Fours: " << fours << "\n";
	cout << "   Fives: " << fives << "\n";
	*/
	return 0;
} 