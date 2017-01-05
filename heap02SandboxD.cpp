#include <iostream>
#include <cstdlib>
using std::string;
using std::cout;

// find length of baseString, for use in determining where to insert various characters to new memory allocation
int findBaseLength(char * stringBase) {
	int stringBaseLength = 0;
	while (stringBase[stringBaseLength] !=0) {
		stringBaseLength++;
	}
	return stringBaseLength;
}

// find length of insertString, for use in determining where to insert various characters to new memory allocation
int findInsertLength(char * stringInsert) {
	int stringInsertLength = 0;
	while (stringInsert[stringInsertLength] !=0) {
		stringInsertLength++;
	}
	return stringInsertLength;
}


// take insertString, and stuff it into baseString at the location of insertIndex (10).  Point to original char variables for the function, and create a new heap pointer to copy the chars over to a new allocation of larger memory.  Return heap pointer, which will be copied over to resultString in Main.  consider making a new black box for insertion of new string?

char * doInsert(char * stringBase, int indexInsert, char * stringInsert) {
	// assign vars to both string length functions
	int stringBaseLength = findBaseLength(stringBase);
	int stringInsertLength = findInsertLength(stringInsert);
	// allocates size of new string length!
	int totalStringLength = ( findBaseLength(stringBase) + findInsertLength(stringInsert) );
	// assign dynamic heap memory for longer string concatination
	char * stringResult = new char[totalStringLength];
	
	// series of for loops to concatinate strings together:
	for (int i = 0; i < indexInsert; i++) {
		stringResult[i] = stringBase[i];
	}
	for (int j = 0; j < stringInsertLength; j++) {
		stringResult[j + indexInsert] = stringInsert[j];
	}
	for (int k = 0; k < (stringBaseLength - indexInsert); k++) {
		stringResult[k + indexInsert + stringInsertLength] = stringBase[k + indexInsert];
	}

	// return stringResult to pass concatenated string to main()
	return stringResult;
}

int main () {
	// define base String
	char baseString[] = "Long ago, in a galaxy far away...";
	// define where to insert new string within baseString
	int insertIndex = 10;
	// string to insert into baseString
	char insertString[] = "where the deer and the antelope play, ";
	// define pointer var to point to results of doInsert function (prevent memory leak of heap memory)
	char * resultString = doInsert(baseString, insertIndex, insertString);
	// print doInsert / resultString to terminal
	cout << resultString << "\n";
	// deallocate heap memory: no memory leak!
	delete[] resultString;

	return 0;
}
