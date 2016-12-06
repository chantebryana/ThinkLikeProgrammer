// TLAP ch 4.2 exercise
// initial attempt, using arrays on stack instead of dynamic heap pointers
#include <iostream>
#include <cstdlib>
using std::string;
using std::cin;
using std::cout;


void printFunc (char * output, int sLgth) {
	for(int i = 0; i < sLgth; i++) {
		cout << output[i];
	}
}
void substring (char * array, int sPos, int sLgth) {
	char output[sLgth];
	for(int i = (sPos-1); i < (sPos + sLgth - 1); i++) {
		output[i] = array[i];
	}
	printFunc(output, sLgth);
}


int main() {
	int const ALENGTH = 7;
	char a[ALENGTH] = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
	int stringPosition = 3;
	int stringLength = 4;
	substring(a, stringPosition, stringLength);
	cout << "\n";

	return 0;
}
