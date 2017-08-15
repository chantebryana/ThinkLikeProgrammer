// TLAP chapter 4.3 exercise: proto

#include <iostream>
#include <cstdlib>
using std::string;
using std::cin;
using std::cout;


// to begin with, i = 1 for newString[i]
char * replaceFunc(char * oldString, char * repl) {
	char * pA = new char[5];
	pA[0] = oldString[0];
	for (int i = 0; i < 3; i++) {
		pA[i+1] = repl[i];
	}
	pA[4] = oldString[3];
	return pA;
	}

int main () {

	char string[] = "abcd";
	char target[] = "bc";
	char replace[] = "xyz";
	

	char * output = replaceFunc(string, replace);
	cout << output  << "\n";
	delete[] output;

	return 0;
}
