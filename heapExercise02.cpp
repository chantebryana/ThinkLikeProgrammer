// TLAP chapter 4.3 exercise: proto

#include <iostream>
#include <cstdlib>
using std::string;
using std::cin;
using std::cout;

void booProcessing (int & booze) {
	if(booze = 1) {
		cout << "true ";
	} else {
		cout << "false ";
	}
	cout << "\n";
}

void findSame(char * source, char * targ) {
	int boo;  
	for(int i = 0; i < 9; i++) {
		for(int j = 0; j < 1; j++) {
			if( source[i] == targ[j] ) {
				boo = 1;
			} else {
				boo = 0;
			}
			booProcessing (boo);
		}
	}
}

/*
void print(char * source, char * targ) {
	for (int i = 0; i < 9; i ++) {
		if(findSame(source, targ) ) {
			cout << source[i] << " ";
		} else {
			cout << "error ";
		}
	}
	cout << "\n";
}
*/

int main () {
	char a[9] = {'a', 'b', 'c', 'd', 'b', 'c', 'e', 'c', 'b'};
	char target[1] = {'b'};
	char replace[3] = {'z', 'z', 'z'};
	findSame(a, target);
	return 0;
}
