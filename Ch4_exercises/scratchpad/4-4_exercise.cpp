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

//typedef char * array_string;

int length(char * s) {
	int s_length = s[0] - '0'; // s_length s/b equal to # (int) not '#' (char)
	//std::cout << s_length << std::endl;
	return s_length;
}

void output(char * s) {
	int s_length = s[0];
//	int s_length = length(s);
	std::cout << "s_length: " << s_length << std::endl;

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


//char * reverse(char * s) {
void reverse(char * * s) {
	int s_length = (* s)[0];
	//int s_length = length(s);
	//int s_length = 5;
//	char rev_s[s_length];
	char * rev_s = new char[s_length];
	rev_s[0] = (* s)[0];
	//std::cout << "rev_s[0]: " << (int) rev_s[0] << std::endl;
	int j = s_length-1;
	for (int i = 1; i < s_length; i++) {
		//int j = s_length;
		rev_s[i] = (* s)[j];
		j--;
	}
	delete[] * s;
	* s = rev_s;
	//delete[] rev_s;
//	return s;
}


//void reverse(int * a, int * b) {
void reverse(int * * a) {
	int a_length = 5;
	int rev_a[5];
	//int * rev_a = new int[5];
	int j = a_length-1;
	for (int i = 0; i < a_length; i ++) {
		rev_a[i] = (* a)[j];
		//std::cout << rev_a[i] << ", ";
		j--;
	}
	//std::cout << std::endl;
	delete[] * a;
	* a = rev_a;
}

int main() {
	char * my_string = new char[5];
	//my_string[0] = '5'; my_string[1] = 'l'; my_string[2] = 'u'; my_string[3] = 'c'; my_string[4] = 'k';
	my_string[0] = 5; my_string[1] = 'l'; my_string[2] = 'u'; my_string[3] = 'c'; my_string[4] = 'k';
	//int array[5] = {1, 2, 3, 4, 5};
	//int a_b[5];
	int * array = new int[5];
	array[0] = 1; array[1] = 2; array[2] = 3; array[3] = 4; array[4] = 5; 
	output(my_string);
	append(& my_string, 'y');
	output(my_string);
	reverse(& my_string);
	output(my_string);
	//output(reverse(my_string));
	//length(my_string);
	std::cout << character_at(my_string, 3) << std::endl;
	//std::cout << reverse(array, a_b) << std::endl;
	//reverse(array, a_b);
	//reverse(& array);
/*
	for (int i = 0; i < 5; i++) {
		//std::cout << a_b[i];
		std::cout << array[i];
	}
	std::cout << std::endl;
*/
	delete[] my_string;
	delete[] array;
	return 0;
}
