#include "./string.h"

String::String() {
	char_array = new char[1];
	char_array[0] = 0;
}

char * String::get_string() {
	return char_array;
}

int String::length(char * new_char_array) {
	int count = 0;
	while (new_char_array[count] != 0) {
		count ++;
	}
	count += 1;
	return count;
}

void String::set_string(char * new_char_array) {
	delete[] char_array;
	int char_length = length(new_char_array);
	char_array = new char[char_length];
	for (int i = 0; i < char_length; i ++) {
		char_array[i] = new_char_array[i];
	}
}

char String::characterAt(int position) {
	return char_array[position];
}

void String::append(char c) {
	int original_length = length(char_array);
	char * append_char_array = new char[original_length + 1];
	for (int i = 0; i < original_length-1; i++) {
		append_char_array[i] = char_array[i];
	}
	append_char_array[original_length-1] = c;
	append_char_array[original_length] = 0;
	delete[] char_array;
	char_array = append_char_array;
}

String::~String() {
	delete[] char_array;
}
