// learning about and playing with copy constructors!
// http://www.geeksforgeeks.org/copy-constructor-in-cpp/

#include<iostream>
#include<cstring> // enables strlen(), strcpy(), among others I'm sure

class String {
	private: 
		char * s;
		int size;
	public: 
		String(const char * str = NULL); // constructor
		~String() { delete [] s; } // destructor
		// CE: why doesn't this need a proper variable to pass as arg after '&'?
		//String(const String & old_str); // copy constructor
		void print() {std::cout << s << std::endl; } // function to print string
		void change(const char * ); // function to change
} ;

// constructor:
String::String(const char * str) {
	size = strlen(str); // strlen() must be 
	s = new char[size+1];
	strcpy(s, str);
}

// function to change: 
void String::change(const char * str) {
	delete [] s;
	size = strlen(str);
	s = new char[size+1];
	strcpy(s, str);
}
/*
// copy constructor: 
// CE: so & old_str is the whole class object, which includes the private variables * s and size, along with maybe the public functions (and public variables if there were any). 
String::String(const String & old_str) { 
	size = old_str.size;
	s = new char[size + 1];
	strcpy(s, old_str.s);
}
*/
int main() {
	String str1("GeeksQuiz");
	String str2 = str1; // CE: deep copies pointer to str1 over to str2 variable using copy constructor defined above

	str1.print(); // what gets printed?
	str2.print();

	str2.change("GeeksforGeeks");

	str1.print(); // what gets printed now?
	str2.print();	

	return 0;
}
