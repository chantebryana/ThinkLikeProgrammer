// learning about and playing with copy constructors!
// https://www.tutorialspoint.com/cplusplus/cpp_copy_constructor.htm

// also great sources on class, objects, and copy constructors: 
// http://www.geeksforgeeks.org/c-classes-and-objects/
// http://www.geeksforgeeks.org/copy-constructor-in-cpp/

#include <iostream>
#include <cstdlib>
#include <typeinfo> // for 'typeid' to work

class Line {
	public: 
		int getLength (void);
		Line (int len); // simple constructor
		//Line (const Line &obj); // copy constructor
		Line (const Line * * obj);
		~Line(); // destructor

	private: 
		int * ptr;
} ;

// member functions definitions including constructor: 
Line::Line(int len) {
	std::cout << "Normal constructor allocating ptr" << std::endl;
	// allocate memory for the pointer: 
	ptr = new int; 
	* ptr = len;
}

//Line::Line(const Line & obj) {
Line::Line(const Line * * obj) {
	std::cout << "Copy constructor allocating ptr." << std::endl;
	ptr = new int; 
	* ptr = * obj.ptr; // copy the value. CE: how can 'ptr' have dot-notation?
	// this is how: http://www.geeksforgeeks.org/c-classes-and-objects/
}
/*
try to run with * * and get this error in terminal: 

ruby@rubyVM:~/Projects/ThinkLikeProgrammer/Ch5_exercises/sandbox$ g++ copy_constructor_01.cpp -o ../bin/copy_constructor_01
copy_constructor_01.cpp: In constructor ‘Line::Line(const Line**)’:
copy_constructor_01.cpp:36:16: error: request for member ‘ptr’ in ‘obj’, which is of non-class type ‘const Line**’
  * ptr = * obj.ptr; // copy the value. CE: how can 'ptr' have dot-notation?
                ^~~
*/

Line::~Line(void) {
	std::cout << "Freeing memory!" << std::endl;
	delete ptr;
}

int Line::getLength (void) {
	return * ptr;
}

// non-class function (uses functions definied within class):
//void display(Line obj) {
void display(Line & obj) {
	std::cout << "Length of line: " << obj.getLength() << std::endl;
}


int main() {
	//Line line1(10);
	Line line1 = 10;
	Line line2 = line1; // this also calls copy constructor
	display(line1);
	display(line2);
	return 0;
}
