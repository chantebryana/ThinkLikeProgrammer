#include <iostream>
#include <cstdlib>
#include "./string.h"

int main () {
	String word;
	char user_chars[5] = {'a', 'b', 'c', 'd', 0}; 
	char second_char[4] = "zed";
	word.set_string(user_chars);
	std::cout << word.get_string() << std::endl;
	std::cout << word.characterAt(2) << std::endl;
	word.append('?');
	std::cout << word.get_string() << std::endl;
	word.concatenate(second_char);
	std::cout << word.get_string() << std::endl;

	return 0;
}
