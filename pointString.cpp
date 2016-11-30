// Variable-Length String problem, TLAP Ch4
#include <cstdlib>
#include <iostream>
using namespace std;

//take a string and a number and return the character at the position in the string
void characterAt(char * array, int * indexToFind) {
	cout << array[* indexToFind] << "\n";
}

//print the array!
void printIt(char * value, int length) {
	for (int i = 0; i < length; i++) {
		cout << value[i] << " ";
	}
	cout << ".\n";
}

int main() {
	string userString;
	cout << "Enter a single-word string, then press ENTER: ";
	cin >> userString;
	cout << userString[3] << "\n";
	int const aLength = 5;
	char a[aLength] = {'a', 'b', 'c', 'd', 'e'};
	int positionIndex = 3;
	int * positionPointer = &positionIndex;
//	characterAt(a, positionPointer);
	return 0;
}
