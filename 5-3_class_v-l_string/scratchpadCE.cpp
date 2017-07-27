#include <iostream>
#include <cstdlib>
/*
int age_of_car (int * pnow_yr, int * pcar_yr) {
	return * pnow_yr - * pcar_yr;
}
*/

class String {
	public: 
		String(); // constructor
		char * get_string();
		void set_string();
		~String(); // destructor
	private: 
		char * char_array;
};

String::String() {
	// bare minimum (this is a NULL string: memory points to NULL): 
	// char_array = NULL;
	// default char_array has one element, which is 0 or null ending (this is an empty string, or ""):
	char_array = new char[1];
	char_array[0] = 0;
//	char_array = new char[5];
//	char_array[0] = 'z'; char_array[1] = 'e'; char_array[2] = 's'; char_array[3] = 't'; char_array[4] = 0;
}

char * String::get_string() {
	return char_array;
}

void String::set_string(char * new_char_array) {
	dereference char_array
	figure out length of char_array (const int LENGTH = 5, for instance)
	allocate: char_array = new char[5];
	for (i = 0; i < LENGTH; i ++) {
		char_array[i] = new_char_array[i];
	}
}

String::~String() {
	delete[] char_array;
}

int main () {
	String word;
	// all versions of the same thing (lines 49 - 53): 
	char * user_chars[5] = {'a', 'b', 'c', 'd', 0};
	char * user_chars[5] = "abcd";
	word.set_string(user_chars);
	word.set_string({'a', 'b', 'c', 'd', 0});
	word.set_string("abcd");
	std::cout << word.get_string() << std::endl;

/*
	typedef char * arrayString;
	char * a = new char[5];
	a[0] = 't'; a[1] = 'e'; a[2] = 's'; a[3] = 't'; a[4] = 0;
//	std::cout << a << std::endl;
	String word;
	std::cout << word.get_string() << std::endl;
	delete[] a;
*/
/*
	int car_year = 1999;
	int now_year = 2017;
	//int * pcar_year;
	int * pcar_year = new int;
	int * pnow_year;
	pcar_year = & car_year;
	pnow_year = & now_year;
	std::cout << pnow_year << " minus " << pcar_year << " equals " << pnow_year - pcar_year << std::endl;

	std::cout << "age of car: " << age_of_car(pnow_year, pcar_year) << " years" << std::endl;
//	std::cout << "Age of car: " << * pnow_year - * pcar_year << " years old" << std::endl;
*/
	return 0;
}
