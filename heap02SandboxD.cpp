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


// take insertString, and stuff it into baseString at the location of insertIndex (10).  Point to original char variables for the function, and create a new heap pointer to copy the chars over to a new allocation of larger memory.  Return heap pointer, which will be copied over to resultString in Main.  consider making a new black box for insertion of new string?

char * doInsert(char * stringBase, int indexInsert, char * stringInsert) {
	// assign vars to both string length functions
	int stringBaseLength = findStringLength(stringBase);
	int stringInsertLength = findStringLength(stringInsert);
	// allocates size of new string length!
	int totalStringLength = ( findStringLength(stringBase) + findStringLength(stringInsert) );
	// assign dynamic heap memory for longer string concatination
	char * stringResult = new char[totalStringLength];
	
	// series of for loops to concatinate strings together:
		// indices 0 - 9:
	for (int i = 0; i < indexInsert; i++) {
		stringResult[i] = stringBase[i];
	}
		// indices 10 - 37:
	for (int j = 0; j < stringInsertLength; j++) {
		stringResult[j + indexInsert] = stringInsert[j];
	}
		// indices 38 - __ (includes null character space)
	for (int k = indexInsert; k <= (stringBaseLength - indexInsert); k++) {
		stringResult[k + stringInsertLength] = stringBase[k];
	}

	// return stringResult to pass concatenated string to main()
	return stringResult;
}

int main () {
	// define base String
	//char baseString[] = "Long ago, in a galaxy far away...";
	char baseString[] = "abcd";
	// define where to insert new string within baseString
	int insertIndex = 2;
	// string to insert into baseString
	//char insertString[] = "where the deer and the antelope play, ";
	char insertString[] = "xy";
	// define pointer var to point to results of doInsert function (prevent memory leak of heap memory)
	char * resultString = doInsert(baseString, insertIndex, insertString);
	// print doInsert / resultString to terminal
	cout << resultString << "\n";
	// deallocate heap memory: no memory leak!
	delete[] resultString;

	return 0;
}
