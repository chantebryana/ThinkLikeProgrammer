#include <iostream>
using namespace std;

//define those arrays!!
int firstArray[] = {5, 10, 15};
int secondArray[] = {2, 4, 6, 8, 10};

//iterating through array function 
void printArray (int arg[], int length) {
	for (int n = 0; n < length; n++) {
		cout << arg[n] << " ";
	}
}

//ugly but it works: printing out arrays on the screen using above ints and function
int main () {
	cout << "First Array: ";
	printArray(firstArray, 3);
	cout << "\n";
	cout << "Second Array: ";
	printArray(secondArray, 5);
	cout << "\n";
	return 0;
}