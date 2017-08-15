#include <iostream>
#include <cstdlib>
using std::string;
using std::cout;

void checkFunction(char * string, char * targ, char * repl) {
	int i = 4; // simulate a previous for loop, where i stops at index 1 to evaluate the first-occuring "b" in baseString
	int outputVar = 0;
	for (int j = 1; j < 2; j++) { // 2 is length of target; i+1 is one character past "b" at index 1 in baseString
		//for (int k = 1; k < 2+1; k++) { // 2 is length of target
		if (string[j+i] != targ[j]) {
			outputVar = 0;
			cout << string[j+i] << "; It didn't work.\n"; 
			break;
		} else if (string[j+i] == targ[j]) {
			outputVar = 1;
		}
		//}
	}
	if (outputVar = 1) {
		cout << "Yay it worked!\n";
	}
}

int main() {
	char baseString[] = "abcdbz";
	char target[] = "bc";
	char replace[] = "xyz";
	checkFunction(baseString, target, replace);
	return 0;
}
