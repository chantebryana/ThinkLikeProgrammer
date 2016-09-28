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
		tallyArray[(surveyResponses[i])-1]++;
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
	//print out tallied answers; results of eachNumCount function
	cout << "Tally of Survey Responses:\n";
	cout << "  Ones: " << tallyArray[0] << "\n";
	cout << "  Twos: " << tallyArray[1] << "\n";
	cout << "Threes: " << tallyArray[2] << "\n";
	cout << " Fours: " << tallyArray[3] << "\n";
	cout << " Fives: " << tallyArray[4] << "\n";
	return 0;
} 