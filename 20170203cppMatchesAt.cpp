#include <iostream>
#include <cstdlib>
#include <cstring>
using std::cout;

// compares base string to target string and verifies whether they match with boolean returns: if boo_in_the_zoo returns 0 it's false (no match), if it returns 1 it's true (full-match)
int matches_at_bool(char * in_this_string, char * do_i_find, int at_this_index) {
	int boo_in_the_zoo;
	int do_i_find_length = strlen(do_i_find);
	for (int i = 0; i < do_i_find_length; i++) {
		if (in_this_string[i + at_this_index] != do_i_find[i]) {
			boo_in_the_zoo = 0;
			break;
		} else {
			boo_in_the_zoo = 1;
		}
	}
	return boo_in_the_zoo;
}

// function passes over all of base string, checks for any matches with target, and returns the index of the match if it's there; if there's no match, it returns -1 (a non-answer, since any match would return a number that starts at 0)
int log_matching_index(char * in_this_string, char * do_i_find) {
	int matchingIndex = -1;
	int in_this_string_length = strlen(in_this_string);
	for (int i = 0; i < in_this_string_length; i++) {	// or remove this line
		if (in_this_string[i] == do_i_find[0]) {
			if (matches_at_bool(in_this_string, do_i_find, i)) {
				matchingIndex = i;	// or return i;
				break;					// or remove this line
			}
		}
	}										// or remove this line too
	return matchingIndex;			// or return -1;
}

/*
// printing logic / microstep to next dependent function logic
int log_matching_index(char * in_this_string, char * do_i_find, int at_this_index) {
	int boo_in_the_zoo = matches_at_bool(in_this_string, do_i_find, at_this_index);
	int matchingIndex = -1;
	if (boo_in_the_zoo) {
		matchingIndex = at_this_index;
	}
	return matchingIndex;
}
*/

// assuming the other functions work assuming "true", this function copies base + replace strings to outputVar
char * scanMatchReplace (char * in_this_string, char * do_i_find, char * replaceVar) {
	char * outputVar = new char[100];
	int matchingIndex = log_matching_index(in_this_string, do_i_find);
	int replaceLength = strlen(replaceVar);
	int targetLength = strlen(do_i_find);
	int baseLength = strlen(in_this_string);
	
	for (int i = 0; i < (matchingIndex); i++) {
		outputVar[i] = in_this_string[i];
	}
	for (int j = 0; j < replaceLength; j++) {
		outputVar[j + matchingIndex] = replaceVar[j];
	}
	for (int k = (matchingIndex); k < baseLength; k++) {
		outputVar[k + replaceLength] = in_this_string[k + targetLength];
	}
	return outputVar;
}

int main () {
	char base[] = "there once was a man from nantucket";
	char find[] = "a man from";
	char replace[] = "two foxes inside";
	//int matchingIndex = log_matching_index(base, find, 15);
//	printIfMatches(base, find, 15);
//	cout << where_at(base, find) << "\n";
/*
	if (matches_at_log_index(base, find, 15)) {
		cout << "found it where expected\n";
	} else {
		cout << "didn't twerk\n";
	}
*/
	char * outputVar = scanMatchReplace(base, find, replace);
	cout << outputVar << "\n";
	delete[] outputVar;
	return 0;
}

