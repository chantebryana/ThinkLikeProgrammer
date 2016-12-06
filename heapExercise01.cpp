// TLAP ch 4.2 exercise
// initial attempt, using arrays on stack instead of dynamic heap pointers
#include <iostream>
#include <cstdlib>
using std::string;
using std::cin;
using std::cout;


void printFunc (char * output, int sLgth) {
	for(int j = 0; j < sLgth; j++) {
		cout << output[j];
	}
}
void substring (char * array, int sPos, int sLgth) {
	char output[sLgth];
	for (int j = 0; j < sLgth; j++) {
		for(int i = sPos; i < (sLgth+1); i++) {
			output[j] = array[i];
		}
	}
	printFunc(output, sLgth);
}

int main() {
	int const ALENGTH = 7;
	char a[ALENGTH] = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
	int stringPosition = 2;
	int stringLength = 4;
	substring(a, stringPosition, stringLength);
	cout << "\n";

	return 0;
}
