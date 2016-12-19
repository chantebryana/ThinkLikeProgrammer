// TLAP chapter 4.3 exercise: proto

#include <iostream>
#include <cstdlib>
using std::string;
using std::cin;
using std::cout;


// to begin with, i = 1 for newString[i]
void replaceFunc(char * oldString, char * repl) {
	char * pA = new char[5];
	pA[0] = oldString[0];
	cout << pA << "\n";
	for (int i = 0; i < 4; i++) {
		pA[i+1] = repl[i];
	}
	cout << pA << "\n";
	pA[4] = oldString[3];
	cout << pA << "\n";
	delete[] pA;
	}

int main () {

	char string[] = "abcd";
	char target[] = "bc";
	char replace[] = "xyz";
	
	replaceFunc(string, replace);
	/*
	char * output = replaceFunc(string, replace);
	cout << output  << "\n";
	delete[] output;
	*/
/*
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
*/
	return 0;
}
