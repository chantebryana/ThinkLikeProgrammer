#include <iostream>
#include <cstdlib>
#include "./string.h"

int main () {
	String word;
	char user_chars[5] = {'a', 'b', 'c', 'd', 0}; // not char *
	//char second_char[4] = "zed";
	char * second_char = new char[4];
	//second_char = {'z', 'e', 'd', 0};
	second_char[0] = 'z'; second_char[1] = 'e'; second_char[2] = 'd'; second_char[3] = 0; 
	word.set_string(user_chars);
	std::cout << word.get_string() << std::endl;
	std::cout << word.characterAt(2) << std::endl;
	word.append('?');
	std::cout << word.get_string() << std::endl;
	word.concatenate(second_char);
	std::cout << word.get_string() << std::endl;

	return 0;
}
