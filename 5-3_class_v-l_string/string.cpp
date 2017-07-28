#include <iostream>
#include <cstdlib>
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

void String::concatenate(char * char_array_b) {
	int original_length_a = length(char_array);
	//std::cout << "original_length_a: " << original_length_a << std::endl;
	int length_b = length(char_array_b)-1;
	//std::cout << "length_b: " << length_b << std::endl;
	int new_length_ab = original_length_a + length_b;
	//std::cout << "new_length_ab: " << new_length_ab << std::endl;
	char * cat_char_array = new char[new_length_ab + 1];
	//std::cout << "cat_char_array length: " << length(cat_char_array) << std::endl;
	for (int i = 0; i < original_length_a-1; i++) {
		cat_char_array[i] = char_array[i];
	}
	for (int i = 0; i < length_b-1; i++) {
		cat_char_array[original_length_a + i] = char_array_b[i];
	}
	cat_char_array[new_length_ab] = 0;
	delete[] char_array;
	char_array = cat_char_array;
}

String::~String() {
	delete[] char_array;
}
