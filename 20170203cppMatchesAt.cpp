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

// printing logic / microstep to next dependent function logic
int log_matching_index(char * in_this_string, char * do_i_find, int at_this_index) {
	int boo_in_the_zoo = matches_at_bool(in_this_string, do_i_find, at_this_index);
	int matchingIndex = 0;
	if (boo_in_the_zoo) {
		matchingIndex = at_this_index;
	}
	return matchingIndex;
}

char * scanMatchReplace (char * in_this_string, char * do_i_find, char * replaceVar, int at_this_index) {
	char * outputVar = new char[100];
	int matchingIndex = log_matching_index(in_this_string, do_i_find, at_this_index);
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
	int matchingIndex = log_matching_index(base, find, 14);
//	printIfMatches(base, find, 15);
//	cout << where_at(base, find) << "\n";
/*
	if (matches_at_log_index(base, find, 15)) {
		cout << "found it where expected\n";
	} else {
		cout << "didn't twerk\n";
	}
*/
	char * outputVar = scanMatchReplace(base, find, replace, matchingIndex);
	cout << outputVar << "\n";
	delete[] outputVar;
	return 0;
}

