// string::find
// http://www.cplusplus.com/reference/string/string/find/

// string::replace
// http://www.cplusplus.com/reference/string/string/replace/
#include <iostream>
#include <string> 
#include <cstdlib>
using std::string;
using std::cout;


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


string * searchAndDestroy(string * stringBase, string * stringTarget, string * stringReplace) {
	int searchVar = stringBase->find(* stringTarget);
	if (searchVar >= 0) {
		stringBase->replace(searchVar, stringTarget->length(), * stringReplace);
	}
	return stringBase;
}


int main () {
	string base ("this is a test string.");
	string target ("t");
	string replace ("fw");
	//char base[] = "this is a test string.";
	//char target[] = "t";
	//char replace[] = "f";

//	int searchVar = base.find(target);
//	if (searchVar >=0) {
//		base.replace(searchVar, target.length(), replace);
//	}
//	cout << base << "\n";
	cout << * searchAndDestroy(& base, & target, & replace) << "\n";
	return 0;
}

/*
int main () {
	std::string base = "this is a test string.";
	std::string str2 = "n example";
	std::string str3 = "sample phrase";
	std::string str4 = "useful.";

	std::string str = base; // this is a test string."
	std::cout << str << "\n";

	//replace, using positions:
	// str.replace(starting_index, for_how_long_count, replacement_phrase_or_var);
	str.replace(8, 6, "just a"); // "this is just a phrase."
	std::cout << str << "\n";

	// replace, using iterators:
	str.replace(str.begin(), str.begin()+6, "replace");
	std::cout << str << "\n";
	return 0;
}
*/

