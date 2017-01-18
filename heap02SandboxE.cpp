#include <iostream>
#include <cstdlib>
using std::string;
using std::cout;

// generic funciton to find length of string, to use in doInsert function
int findStringLength(char * string) {
	int stringLength = 0;
	while (string[stringLength] !=0) {
		stringLength++;
	}
	return stringLength;
}

// function counts how many target characters appear in base string, which is used to find how long the new heap memory for new string should be.
int memoryLength(char * string, char * targ, char * repl) {
	int aLength = findStringLength(string);
	// extraMemoryLength: amount of extra memory when target string length is taken out of replace string length (ex: target "b" = 1, replace "xyz" = 3, but we only need 2 more memory because target "b" is being replaced by "xyz": 3-1.
	int extraMemoryLength = findStringLength(repl) - findStringLength(targ);
	int numberOfBs = 0;
	for (int i = 0; i < aLength; i++) {
		if (string[i] == targ[0]) {
			numberOfBs++;
		}
	}
	int newMemoryLength = aLength + (numberOfBs * extraMemoryLength) + 1; // base length + extra length of added "replace" characters + 1 extra for 0 at end of C-string
	return newMemoryLength;
}

char * outputFunc(char * string, char * targ, char * repl) {
	int newMemoryLength = memoryLength(string, targ, repl);
	char * outputString = new char[newMemoryLength];
	for (int i = 0; i < newMemoryLength-1; i++) {
		outputString[i] = 'a';
	}
	//outputString[newMemoryLength-1] = targ[0];
	outputString[newMemoryLength] = 0;
	//outputString[4] = ' ';
	return outputString;
}

int main () {
	char a[] = "abcbdbbc";
	char target[] = "bc";
	char replace[] = "xyz";
	cout << memoryLength(a, target, replace) << "\n";
	char * endResultString = outputFunc(a, target, replace);
	cout << endResultString << "\n";
	delete[] endResultString;
	return 0;
}
