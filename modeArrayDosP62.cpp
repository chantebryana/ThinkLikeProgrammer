#include <iostream>
#include <cstdlib>
using std::cin;
using std::cout;

//define junk for later 
int i;
const int A_LENGTH = 19;

//define comparison function for qsort
int compareFunc(const void *voidA, const void *voidB) {
	int *intA = (int *)(voidA);
	int *intB = (int *)(voidB);
	return *intA - *intB;
}

int main () {
	//create unsorted array of survey responses 
	//int surveyResponses [A_LENGTH] = {2, 5, 9, 1, 5, 4, 7, 8, 6, 2, 10, 7, 4, 5, 6, 10, 9, 1, 1};
	int surveyResponses [A_LENGTH] = {2, 5, 4, 1, 5, 4, 2, 3, 1, 2, 5, 2, 4, 5, 1, 5, 4, 1, 1}; //simlified: 1 to 5
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
	return 0;
} 