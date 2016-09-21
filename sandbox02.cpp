#include <iostream>
using namespace std;

//define those arrays!!
const int ARRAY_LENGTH = 10;
int tallyArr[ARRAY_LENGTH];

//set values of tallyArr to 0
void arrSet(int *arrayz) {
	for (int i = 0; i < ARRAY_LENGTH; i++) {
		arrayz[i] = 0;
	}
} 

//iterate through array for printing out on screen
void arrPrint(int *array) {
	for (int n = 0; n < ARRAY_LENGTH; n++) {
		cout << array[n] << " ";
	}
}

//call the arrPrint function in main 
int main () {
	arrSet(tallyArr);
	arrPrint(tallyArr);
	cout << "\n";
	return 0;
}