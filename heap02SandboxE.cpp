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
	int aLength = findStringLength(string); // length of base string
	int extraMemoryLength = findStringLength(repl) - findStringLength(targ); // extraMemoryLength: amount of extra memory when target string length is taken out of replace string length (ex: target "b" = 1, replace "xyz" = 3, but we only need 2 more memory because target "b" is being replaced by "xyz": 3-1.
	int numberOfTargs = 0; // declare number of instances that Target appears in base string
	// loop to iterate through base string to find how many times the first character of Target string appears in base string; increment numberOfTargs by 1 for each match
	for (int i = 0; i < aLength; i++) {
		if (string[i] == targ[0]) {
			numberOfTargs++;
		}
	}
	int newMemoryLength = aLength + (numberOfTargs * extraMemoryLength) + 1; // base length + extra length of added "replace" characters + 1 extra for 0 at end of C-string
	return newMemoryLength; // return newMemoryLength to pass onto outputFunc
}

// assign characters to outputString: either base string or replacement string
char * outputFunc(char * string, char * targ, char * repl) {
	int newMemoryLength = memoryLength(string, targ, repl); // define length of final output string
	char * outputString = new char[newMemoryLength]; // heap variable for final output string
	// assignment logic loop
	for (int i = 0; i < newMemoryLength-1; i++) {
		if (string[i] != targ[0]) {
			outputString[i] = string[i];
		} else if (string[i] == targ[0]) {
			outputString[i] = repl[0];
		}
	}
	outputString[newMemoryLength] = 0; // assign 0 to end of C-String
	return outputString;
}

int main () {
	char a[] = "abcdbbc"; // base string
	char target[] = "b"; // target string
	char replace[] = "xy"; // replacement string
	cout << memoryLength(a, target, replace) << "\n"; // verify that memoryLength func works
	char * endResultString = outputFunc(a, target, replace); // pass heap variable in outputFunc to new heap variable in main()
	cout << endResultString << "\n"; // print outputString
	delete[] endResultString; // deallocate heap memory: no leaking!
	return 0;
}
