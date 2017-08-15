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

// this work-in-progress function finds the first character of the first-occurring target.
int findTargLocation(char * string, char * targ) {
	int targIndex = 1; // start at 1 instead of 0 to make the numbers line up
	int aLength = findStringLength(string);
	// iterate through base string increment targIndex until the first target is found
	for (int i = 0; i < aLength; i++) {
		if (string[i] != targ[0]) {
			targIndex++;
		} else if (string[i] == targ[0]) {
			break;
		}
	}
	return targIndex;  // return targIndex to be used in later functions
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

char * doInsert(char * string, char * targ, char * repl, int indexInsert) {
	int aLength = findStringLength(string); // base string length
	int stringInsertLength = findStringLength(repl); // replacement string length
	int newMemoryLength = memoryLength(string, targ, repl); // final string length

	char * earlierString = outputFunc(string, targ, repl); // "axcd": deallocate this variable before the end of the function!
	char * finalString = new char[newMemoryLength]; // heap var for final output string; return at end of this function, utilize in main(), then deallocate before end of main()

	for(int i = 0; i < indexInsert; i++) {
		finalString[i] = earlierString[i]; // assign chars from earlierString located before indexInsert (ie, the beginning part of the string)
	}
	for(int j = 0; j< (stringInsertLength - 1); j++) {  // minus 1 to account for first char ('x') already being included in earlierString
		finalString[j + indexInsert] = repl[j+1]; // plus 1 for same reason as above comment; assign chars from repl located after initial index
	}
	for(int k = indexInsert; k<=(newMemoryLength - indexInsert); k++) {
		finalString[k + stringInsertLength - 1] = string[k]; // assign chars after insertIndex (ie, remainder of earlierString)
	}

	delete[] earlierString;
	return finalString;
}

int main () {
	char a[] = "abcd"; // base string
	char target[] = "b"; // target string
	char replace[] = "xy"; // replacement string
	cout << "Memory location: " << memoryLength(a, target, replace) << "\n"; // verify that memoryLength func works
	int targIndex = findTargLocation(a, target);
	cout << "Target location: " << targIndex << "\n"; 
	//	int insertIndex = 2; // define where to insert 'y'; eventually I'd like to create a function to find this number
	char * finalOutputString = doInsert(a, target, replace, targIndex);
	cout << finalOutputString << "\n";
	delete[] finalOutputString;
	return 0;
}

