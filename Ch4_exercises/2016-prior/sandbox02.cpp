#include <iostream>
using namespace std;

//define those arrays!!
const int RESPONSE_RANGE = 10;
int tallyArr[RESPONSE_RANGE];
int i, n;

//set values of tallyArr to 0, also print index of array 
void arrSet(int *arrayz) {
	for (i = 0; i < RESPONSE_RANGE; i++) {
		arrayz[i] = 0;
		cout << i << " ";
	}
} 

//iterate through array for printing out on screen
void arrPrint(int *array) {
	for (n = 0; n < RESPONSE_RANGE; n++) {
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