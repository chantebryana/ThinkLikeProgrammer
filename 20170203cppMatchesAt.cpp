#include <iostream>
#include <cstdlib>
#include <cstring>
using std::cout;

// compares base string to target string and verifies whether they match with boolean returns: if boo_in_the_zoo returns 0 it's false (no match), if it returns 1 it's true (full-match)
int matches_at_bool(char * baseVar, char * targetVar, int at_this_index) {
	int boo_in_the_zoo;
	int targetVar_length = strlen(targetVar);
	for (int i = 0; i < targetVar_length; i++) {
		if (baseVar[i + at_this_index] != targetVar[i]) {
			boo_in_the_zoo = 0;
			break;
		} else {
			boo_in_the_zoo = 1;
		}
	}
	return boo_in_the_zoo;
}

// function passes over all of base string, checks for any matches with target, and returns the index of the match if it's there; if there's no match, it returns -1 (a non-answer, since any match would return a number that starts at 0)
int log_matching_index(char * baseVar, char * targetVar, int basePlaceholder) {
	int matchingIndex = -1;			// or remove this line
	int baseVar_length = strlen(baseVar);
	for (int i = basePlaceholder; i < baseVar_length; i++) {	// or remove this line
		if (baseVar[i] == targetVar[0]) {
			if (matches_at_bool(baseVar, targetVar, i)) {
				matchingIndex = i;	// or return i;
				break;					// or remove this line
			}
		}
	}										// or remove this line too
	return matchingIndex;			// or return -1;
}

/*
// assuming the other functions work assuming "true" and there's only one replacement to be had, this function copies base + replace strings to outputVar
char * scanMatchReplace (char * baseVar, char * targetVar, char * replaceVar) {
	char * outputVar = new char[100];
	int matchingIndex = log_matching_index(baseVar, targetVar);
	int replaceLength = strlen(replaceVar);
	int targetLength = strlen(targetVar);
	int baseLength = strlen(baseVar);
	
	for (int i = 0; i < (matchingIndex); i++) {
		outputVar[i] = baseVar[i];
	}
	for (int j = 0; j < replaceLength; j++) {
		outputVar[j + matchingIndex] = replaceVar[j];
	}
	for (int k = (matchingIndex); k < baseLength; k++) {
		outputVar[k + replaceLength] = baseVar[k + targetLength];
	}
	return outputVar;
}
*/

char * scanMatchReplace (char * baseVar, char * targetVar, char * replaceVar) {
	char * outputVar = new char[100];
	// local variable declarations:
	int outputPlaceholder = 0;
	int basePlaceholder = 0;
	int matchingIndex = log_matching_index(baseVar, targetVar, basePlaceholder);
//	int baseLength = strlen(baseVar);
	int targetLength = strlen(targetVar);
	int replaceLength = strlen(replaceVar);
	int i = 0;
	int j = 0;

	do {
		matchingIndex;
		cout << "beginning matchingIndex: " << matchingIndex << "\n";
		if (matchingIndex >= 0) {
			for (i = 0; i < matchingIndex; i++) {
				outputVar[i + outputPlaceholder] = baseVar[i + basePlaceholder];
			}
			basePlaceholder = i + basePlaceholder + targetLength;
			cout << "basePlaceholder: " << basePlaceholder << "\n";
			for (j = 0; j < replaceLength; j++) {
				outputVar[j + outputPlaceholder + matchingIndex] = replaceVar[j];
			}
			outputPlaceholder = j + outputPlaceholder + matchingIndex;
			cout << "outputPlaceholder: " << outputPlaceholder << "\n";
			matchingIndex = log_matching_index(baseVar, targetVar, basePlaceholder);
			cout << "end matchingIndex: " << matchingIndex << "\n";
		}
	} while (matchingIndex >= 0);
	return outputVar;	
}

int main () {
	char base[] = "I say, dogs eat dogs on dogs for lunch";
	char target[] = "dogs";
	char replace[] = "hippos";
	cout << "Base Phrase:   ";
	for (int i = 0; i < (strlen(base)); i++) {
		cout << base[i];
	}
	cout << "\n";

	char * outputVar = scanMatchReplace(base, target, replace);
	cout << "Output Phrase: " << outputVar << "\n";
	delete[] outputVar;
	return 0;
}

