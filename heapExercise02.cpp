// TLAP chapter 4.3 exercise: proto

#include <iostream>
#include <cstdlib>
using std::string;
using std::cin;
using std::cout;

int findSame(char * source, char * targ) {
	for(int i = 0; i < 9; i++) {
		for(int j = 0; j < 2; j++) {
			if( source[i] == targ[j] ) {
				return 1;
			} else {
				return 0;
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
	char a[9] = {'a', 'b', 'c', 'd', 'b', 'c', 'e', 'c', 'b'};
	char target[2] = {'b', 'c'};
	char replace[3] = {'z', 'z', 'z'};
	print(a, target);
	return 0;
}
