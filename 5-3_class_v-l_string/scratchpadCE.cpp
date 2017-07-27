#include <iostream>
#include <cstdlib>

class String {
	public: 
		String(); // constructor
		char * get_string();
		void set_string(char * new_char_array);
		char characterAt(int position);
		~String(); // destructor
	private: 
		char * char_array;
		int length(char * new_char_array);
};

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

String::~String() {
	delete[] char_array;
}

int main () {
	String word;
	char user_chars[5] = {'a', 'b', 'c', 'd', 0}; // not char *
	word.set_string(user_chars);
	std::cout << word.get_string() << std::endl;
	std::cout << word.characterAt(2) << std::endl;

	return 0;
}
