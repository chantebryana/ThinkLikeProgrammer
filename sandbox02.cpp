#include <iostream>
using namespace std;

//define those arrays!!
const int ARRAY_LENGTH = 10;
int tallyArr[ARRAY_LENGTH];
int i, n;

//set values of tallyArr to 0, also print index of array 
void arrSet(int *arrayz) {
	for (i = 0; i < ARRAY_LENGTH; i++) {
		arrayz[i] = 0;
		cout << i << " ";
	}
} 

//iterate through array for printing out on screen
void arrPrint(int *array) {
	for (n = 0; n < ARRAY_LENGTH; n++) {
		cout << array[n] << " ";
	}
}

//call the arrPrint function in main 
int main () {
	cout << "array indices: ";
	arrSet(tallyArr);
	cout << "\n" << "array values: ";
	arrPrint(tallyArr);
	cout << "\n";
	return 0;
}