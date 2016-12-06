// TLAP ch 4.2 exercise
// initial attempt, using arrays on stack instead of dynamic heap pointers
#include <iostream>
#include <cstdlib>
using std::string;
using std::cin;
using std::cout;

// generic printing-of-an-array function
void printFunc (char * output, int sLgth) {
	for(int j = 0; j < sLgth; j++) {
		cout << output[j];
	}
}

// create a new array "output" to print only the subset of chars from original "array"
void substring (char * array, int sPos, int sLgth) {
	char output[sLgth];
	int count = 0;
	for(int i = sPos; i < (sLgth+sPos); i++) {
		output[count] = array[i];
		count ++;
	}
	printFunc(output, sLgth);
}

// literal reassignment func for testing purposes
void substringLiteral(char * array, int sLgth) {
	char output[sLgth];
	output[0] = array[2];
	output[1] = array[3];
	output[2] = array[4];
	output[3] = array[5];
	printFunc(output, sLgth);
}

int main() {
	int const ALENGTH = 7;
	char a[ALENGTH] = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
	int stringPosition = 2;		// where to start at the char array
	int stringLength = 4;		// how long to keep looking for
	substring(a, stringPosition, stringLength);
	cout << "\n";

	return 0;
}
