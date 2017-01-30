// string::find
// http://www.cplusplus.com/reference/string/string/find/

// string::replace
// http://www.cplusplus.com/reference/string/string/replace/
#include <iostream>
#include <string> 

/*
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
*/

int main () {
	std::string base = "this is a test string.";
	std::string str2 = "n example";
	std::string str3 = "sample phrase";
	std::string str4 = "useful.";

	std::string str = base; // this is a test string."
	std::cout << str << "\n";

	//replace, using positions:
	str.replace(8, 6, "just a"); // "this is just a phrase."
	std::cout << str << "\n";

	// replace, using iterators:
	str.replace(str.begin(), str.begin()+6, "replace");
	std::cout << str << "\n";
	return 0;
}
