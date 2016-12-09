// TLAP chapter 4.3 exercise: proto

#include <iostream>
#include <cstdlib>
using std::string;
using std::cin;
using std::cout;

int findSame(char * source, char * targ) {
	for(int i = 0; i < 9; i++) {
		for(int j = 0; j < 1; j++) {
			if( source[i] == targ[j] ) {
				int booT = 1; // marker to "return" 1 or true: use in separate func
			} else {
				int booF = 0; // marker to "return" 0 or false: use in separate func
			}
		}
	}
}

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

int main () {
	char a[9] = {'b', 'b', 'c', 'd', 'b', 'c', 'e', 'c', 'b'};
	char target[1] = {'b'};
	char replace[3] = {'z', 'z', 'z'};
	print(a, target);
	return 0;
}
