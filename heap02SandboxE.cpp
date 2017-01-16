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

// function counts how many target characters appear in base string. Result returned to another function which will use return value to determine how long end-result string will be.
int memoryLength(char * string, char * targ) {
	int aLength = findStringLength(string);
	int numberOfBs = 0;
	for (int i = 0; i < aLength; i++) {
		if (string[i] == targ[0]) {
			numberOfBs++;
		}
	}
	return numberOfBs;
}

int main () {
	char a[] = "abcd";
	char target[] = "b";
	char replace[] = "xy";
	cout << memoryLength(a, target) << "\n";
	return 0;
}
