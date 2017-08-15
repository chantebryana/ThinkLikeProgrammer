// TLAP chapter 4.3 exercise: proto

#include <iostream>
#include <cstdlib>
using std::string;
using std::cin;
using std::cout;

// replacement function template. in function argument section, should the address of source be dereferenced? should the function return source or source[i]? Ultimately, this function may never be used, because it kind of assumes a one-for-one swap out, which won't work as written if target and replaceText are different lengths.
char * replaceFunc(char * source, int * i, char * target, int * j, char * replaceText int * k) {
	if {source[i] == target[j]) {
		source[i] = replaceText[k];
	}
	return source[i];
}

// another line of thought:
char string = "abcd";
char target = "bc";
char replace = "xyz";

// to begin with, i = 1 for newString[i]
void replaceFunc(char * newString, i, char * replace) {
	if (i == 1) {
		for (int j = 0; j = replace.length; j++) {
			int count = 1;
			newString[count] = replace[j];
			count++;
		}
	}

	cout << newString << "\n";
}

// ending the line of thought

int main () {

	return 0;
}
