// Variable-Length String problem, TLAP Ch4
#include <cstdlib>
#include <iostream>
using namespace std;

//take a string and a number and return the character at the position in the string
void characterAt(char * array, int * indexToFind) {
	cout << array[* indexToFind] << "\n";
}

int main() {
	string userString;
	int userNum;
	cout << "Enter a single-word string, then press ENTER: ";
	cin >> userString;
	cout << "Enter a number less than the length of the word entered above, then press ENTER: ";
	cin >> userNum;
	return 0;
}
