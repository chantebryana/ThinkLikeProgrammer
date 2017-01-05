#include <iostream>
#include <cstdlib>
using std::string;
using std::cout;

int findBaseLength(char * stringBase) {
	int stringBaseLength = 0;
	while (stringBase[stringBaseLength] !=0) {
		stringBaseLength++;
	}
	return stringBaseLength;
}

int findInsertLength(char * stringInsert) {
	int stringInsertLength = 0;
	while (stringInsert[stringInsertLength] !=0) {
		stringInsertLength++;
	}
	return stringInsertLength;
}


// take insertString, and stuff it into baseString at the location of insertIndex (10).  Point to original char variables for the function, and create a new heap pointer to copy the chars over to a new allocation of larger memory.  Return heap pointer, which will be copied over to resultString in Main.  consider making a new black box for insertion of new string?

char * doInsert(char * stringBase, int indexInsert, char * stringInsert) {
	int stringBaseLength = findBaseLength(stringBase);
	int stringInsertLength = findInsertLength(stringInsert);
	// allocates size of new string length!
	int totalStringLength = ( findBaseLength(stringBase) + findInsertLength(stringInsert) );
	char * stringResult = new char[totalStringLength];
	for (int i = 0; i < indexInsert; i++) {
		stringResult[i] = stringBase[i];
	}
	for (int j = 0; j < stringInsertLength; j++) {
		stringResult[j + indexInsert] = stringInsert[j];
	}
	for (int k = 0; k < (stringBaseLength - indexInsert); k++) {
		stringResult[k + indexInsert + stringInsertLength] = stringBase[k + indexInsert];
	}

	return stringResult;
}

int main () {
	char baseString[] = "Long ago, in a galaxy far away...";
	int insertIndex = 10;
	char insertString[] = "where the deer and the antelope play, ";
	char * resultString = doInsert(baseString, insertIndex, insertString);
	cout << resultString << "\n"   ;
	delete[] resultString;
	return 0;
}
