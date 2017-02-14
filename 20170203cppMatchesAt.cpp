#include <iostream>
#include <cstdlib>
#include <cstring>
using std::cout;

// (see full functions at end)
int matches_at_bool(char * baseVar, char * targetVar, int at_this_index);
int log_matching_index(char * baseVar, char * targetVar, int basePlaceholder);

// kinda the main function
char * scanMatchReplace (char * baseVar, char * targetVar, char * replaceVar) {
	char * outputVar = new char[100]; // CE:create function to find outputVar length
	// local variable declarations:
	int outputPlaceholder = 0;
	int basePlaceholder = 0;
	int matchingIndex = log_matching_index(baseVar, targetVar, basePlaceholder); 
	int baseLength = strlen(baseVar);
	int targetLength = strlen(targetVar); 
	int replaceLength = strlen(replaceVar);
	int charDiffLgth = (replaceLength - targetLength); // (behold the magic of math! don't make this an absolute value: if replace is shorter than target, we want a negative number)
	int i = 0;
	int j = 0;
	int k = 0;
	int passesThroughLoop = 0;

	// populate outputVar characters with replacement text from baseVar and replaceVar, based on logic below
	while(1) {	// keeps looping while keepGoing is true
		// transcribe non-target characters of base string over to outputVar
		if (matchingIndex >= 0) {
			for (i = 0; i < matchingIndex; i++) {
				outputVar[i + outputPlaceholder] = baseVar[i + basePlaceholder];
			}
			basePlaceholder = (matchingIndex + targetLength); // iterate basePlaceholder for next pass-through
		} else { // if matchingIndex < 0, ie, the end of baseVar after there are no more replacements to be found
			for (k = 0; k < baseLength; k++) {
				outputVar[k + outputPlaceholder] = baseVar[k + basePlaceholder]; 
			}
			break; // break out of the loop: we're done!
		}
		// if matchingIndex < 0 then there's some replacement text to swap out.  This for loop inserts that replacement text into outputVar
		
		for (j = 0; j < replaceLength; j++) {
			outputVar[j + matchingIndex + (charDiffLgth * passesThroughLoop)] = replaceVar[j];
		}
		outputPlaceholder = (matchingIndex + (charDiffLgth * passesThroughLoop) + replaceLength); // iterate outputPlaceholder for next pass-through
		matchingIndex = log_matching_index(baseVar, targetVar, basePlaceholder); // iterate matchingIndex for next pass-through
		passesThroughLoop++; // iterate passesThroughLoop for next pass-through
	}

	return outputVar;	
}

int main () {
	char base[] = "I say, dogsandwich eat dogsandwich on dogsandwich for lunch";
	char target[] = "dogsandwich";
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
	int matchingIndex = -1;
	int baseVar_length = strlen(baseVar);
	for (int i = basePlaceholder; i < baseVar_length; i++) {
		if (baseVar[i] == targetVar[0]) {
			if (matches_at_bool(baseVar, targetVar, i)) {
				matchingIndex = i;
				break;
			}
		}
	}
	return matchingIndex;
}

