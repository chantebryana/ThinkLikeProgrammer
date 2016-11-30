// Variable-Length String problem, TLAP Ch4
#include <cstdlib>
#include <iostream>
using namespace std;

//take a string and a number and return the character at the position in the string
void characterAt(char * array, int * indexToFind) {
	cout << array[* indexToFind] << "\n";
}

int main() {
	char userString;
	cout << "Enter a single-word string, then press ENTER: ";
	cin >> userString;
	cout << "The string you entered is " << userString << "\n";
	int const aLength = 5;
	char a[aLength] = {'a', 'b', 'c', 'd', 'e'};
	int positionIndex = 3;
	int * positionPointer = &positionIndex;
//	characterAt(a, positionPointer);
	return 0;
}
