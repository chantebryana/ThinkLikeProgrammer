#include <iostream>
#include <cstdlib>
using std::cout;

// compares base string to target string and verifies whether they match with boolean returns: if boo_in_the_zoo returns 0 it's false (no match), if it returns 1 it's true (full-match)
int matches_at(char * in_this_string, char * do_i_find, int at_this_index) {
	int boo_in_the_zoo = 0;
	for (int i = 0; i < 10; i++) {
		if (in_this_string[i + at_this_index] != do_i_find[i]) {
			boo_in_the_zoo = 0;
			break;
		} else {
			boo_in_the_zoo = 1;
		}
	}
	return boo_in_the_zoo;
}

int main () {
	char base[] = "there once was a man frum nantucket";
	char find[] = "a man from";
	if (matches_at(base, find, 15)) {
		cout << "found it where expected\n";
	} else {
		cout << "didn't twerk\n";
	}

	return 0;
}

