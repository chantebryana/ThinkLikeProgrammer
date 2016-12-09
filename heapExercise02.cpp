// TLAP chapter 4.3 exercise: proto

#include <iostream>
#include <cstdlib>
using std::string;
using std::cin;
using std::cout;

// boolean brains and replacement for findSame() 
char * booProcessing (char * source, int & booze, char * replaceVar) {
	for(int i = 0; i < 9; i++) {
		for(int j = 0; j < 1; j++) {
			if(booze == 1) { 	
				source[i] = replaceVar[j];
			}
		}
	}
	return source;
}

// identify matching elements between source and target, process the boolean, then return the end result; findSame called in main()
char * findSame(char * source, char * targ, char * replaceVar) {
	int boo;  
	for(int i = 0; i < 9; i++) {
		for(int j = 0; j < 1; j++) {
			if( source[i] == targ[j] ) {
				boo = 1;
			} else {
				boo = 0;
			}
			booProcessing (source, boo, replaceVar);
		}
	}
	return source;
}

int main () {
	char a[9] = {'a', 'b', 'c', 'd', 'b', 'c', 'e', 'c', 'b'};
	char target[1] = {'b'};
	char replace[1] = {'z'};

	// print and run findSame
	for(int i = 0; i < 9; i++) {
		cout << findSame(a, target, replace) << " ";
	}
	cout << "\n";

	return 0;
}
