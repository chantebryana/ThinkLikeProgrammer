/*
Change the implementation of our strings such that location[0] in the array
stores the size of the array (and therefore location[1] stores the first actual
character in the string), rather than using a null-character terminator.
Implement each of the three functions, append, concatenate, and charactertAt,
taking advantage of the stored size information whenever possible. Because
we’ll no longer be using the null-termination convention expected by the
standard output stream, you’ll need to write your own output function that
loops through its string parameter, displaying the characters.
*/

#include <iostream>
#include <cstdlib>
/*
int length(char * s) {
	int s_length = s[0] - '0'; // s_length s/b equal to # (int) not '#' (char)
	//std::cout << s_length << std::endl;
	return s_length;
}
*/
void output(char * s) {
	int s_length = s[0];
//	int s_length = length(s);
	//std::cout << "s_length: " << s_length << std::endl;

	for (int i = 1; i < s_length; i++) {
		std::cout << s[i];
	}
	std::cout << "\n"; 
}

void append(char * * s, char c) {
//	int old_length = length(s);
	int old_length = (* s)[0]; // parenthesis around * and s (* s) is to make sure that the order of operations goes as desired (ie, * applies to 's' before 's' begins to index at 0...or something
	char * new_s = new char[old_length + 1];
	new_s[0] = ((* s)[0] + 1);
	std::cout << "new_s[0]: " << (int) new_s[0] << std::endl; //(int) typecasts new_s[0] so that cout treats it like an int not a char
	for (int i = 1; i < old_length; i++) {
		new_s[i] = (* s)[i];
	}
	new_s[old_length] = c;
	delete[] * s;
	* s = new_s;
}

char character_at(char * s, int position) {
	return s[position];
}

// reverse that string!
void reverse_char(char * * s) {
	int s_length = (* s)[0];  // define length
	char * rev_s = new char[s_length];  // new heap memory for transfer-over work
	rev_s[0] = (* s)[0];  // first element stays the same: length of array
	int j = s_length-1;  // define j counter OUTSIDE of for loop
	// iterate over rev_s and * s, assigning the *s to rev_s in reverse order:
	for (int i = 1; i < s_length; i++) {
		rev_s[i] = (* s)[j];
		j--;
	}
	delete[] * s;  // deallocate heap memory of original * s (what's defined in main)
	* s = rev_s;  // reallocate it to new reversed order as defined in rev_s
}

// this copies chars from one array to another, regardless of the size of the copied-over-to array (c_s):
void copy(char * s, char * * c_s) {
	int s_length = s[0]; 
	(* c_s)[0] = s[0]; 
	for (int i = 1; i < s_length; i++) {
		(* c_s)[i] = s[i];
	};
}

int compare(char * s, char * comp_s) {
//int compare(char s, char comp_s) {
	if (s[0] != comp_s[0]) {
		std::cout << "Comparison Analysis: Printable Area of strings are not the same!" << std::endl;
		return 0;
	}
	int s_length = s[0];
	for (int i = 1; i < s_length; i++) {
		if (s[i] != comp_s[i]) {
			std::cout << "Comparison Analysis: Printable Area of strings are different!" << std::endl;
			return 0;
		} 
	}
	std::cout << "Comparison Analysis: Printable Area of the strings are the same!" << std::endl;
	return 1;
}

int main() {
	char * my_string = new char[5];
	//my_string[0] = '5'; my_string[1] = 'l'; my_string[2] = 'u'; my_string[3] = 'c'; my_string[4] = 'k';
	my_string[0] = 5; my_string[1] = 'l'; my_string[2] = 'u'; my_string[3] = 'c'; my_string[4] = 'k';
	char * copy_string = new char[1];
	int compare_length = 6;
	//char compare_string[compare_length] = {'l', 'u', 'c', 'k', 'y'};
	char * compare_string = new char[compare_length];
	compare_string[0] = compare_length; compare_string[1] = 'l'; compare_string[2] = 'a'; compare_string[3] = 'c'; compare_string[4] = 'k'; compare_string[5] = 'y'; 
//	std::cout << "compare_string in main: ";
	//output(compare_string);
	char stack_string[4] = {4, 'a', 'b', 'c'};
	char stack_compare[4] = {4, 'a', 'b', 'c'};
	output(my_string);
	append(& my_string, 'y');
	output(my_string);
	reverse_char(& my_string);
	output(my_string);
	reverse_char(& my_string);
	output(my_string);
	copy(my_string, & copy_string);
	std::cout << "copy_string: ";
	output(copy_string);
	std::cout << character_at(my_string, 1) << std::endl;
	compare(my_string, compare_string);  // this will either have its own output, or will return bool true false, which will inform a secondary output function...i guess...
	compare(stack_string, stack_compare);
	delete[] my_string;
	delete[] copy_string;
	return 0;
}
