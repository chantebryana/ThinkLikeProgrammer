// TLAP chapter 4.3 exercise: proto

#include <iostream>
#include <cstdlib>
using std::string;
using std::cin;
using std::cout;

/*
// to begin with, i = 1 for newString[i]
void replaceFunc(char oldString, char repl) {
	char * newString[] = new char[6];
	newString[0] = oldString[0]; 
	for (int i = 1; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
			newString[i] = repl[j];
			}
		}
	}

	cout << newString << "\n";
	delete[] newString;
}
*/

void print(char * a) {
	for (int i = 0; i < 5; i++) {
		cout << a[i] << " ";
	}
	cout << "\n";
}

int main () {

	char string[] = "abcd";
	char target[] = "bc";
	char replace[] = "xyz";

	// based off of append code p 93
	char * pA = new char[5];
	cout << pA << "\n";

	pA[0] = string[0];
	cout << pA << "\n";

	for (int i = 0; i < 3; i++) {
		pA[i+1] = replace[i];
	}
	cout << pA << "\n";
	
	pA[4] = string[3];
	cout << pA << "\n";

	return 0;
}
