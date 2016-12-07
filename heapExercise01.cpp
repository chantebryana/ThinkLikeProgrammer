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

// create a new heap array "output" to print only the subset of chars from original "array"
char * substring (char * array, int sPos, int sLgth) {
	char * pArray = new char[sLgth];	// missing several potential error checks
	int count = 0;
	for(int i = sPos; i < (sLgth+sPos); i++) {
		pArray[count] = array[i];
		count ++;
	}
	return pArray;

//	printFunc(pArray, sLgth); // is this kosher?
//	delete[] pArray; 	// does this properly free heap memory?
}

int main() {
	int const ALENGTH = 7;
	char a[ALENGTH] = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
	int stringPosition = 2;		// where to start at the char array
	int stringLength = 4;		// how long to keep looking for
	char * output = substring(a, stringPosition, stringLength);
	cout << output << "\n";
	delete[] output;

	return 0;
}

