// string::find
// http://www.cplusplus.com/reference/string/string/find/
#include <iostream>
#include <string> 

int main () {
	std::string str ("There are two needles in this haystack with needles.");
	std::string str2 ("needle");

	std::size_t found = str.find(str2);

	// cstring version of function
	found = str.find("needles are small", found+1,6);
	if (found != std::string::npos)
		std::cout << "second 'needle' found at: " << found << "\n";

	// let's replace the first needle: 
	str.replace(str.find(str2), str2.length(), "preposition");
	std::cout << str << "\n";

	return 0;
}
