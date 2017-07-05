#include <iostream>
#include <cstdlib>
using std::string;
using std::cout;

char * replaceB(char * cS, char * pCS, int i) {
	pCS[i] = cS[i];
	return pCS;
}

// 
char * replaceFunc(char * cS, char * target) {
	char * pCS = new char[5];
	for (int i = 0; i < 5; i++) {
		if (cS[i] != target[0]) {
			pCS[i] = cS[i];
		} else {
			replaceB(cS, pCS, i);
		}
	}
	return pCS;	
}

int main () {
	char cString[] = "abcd";
	char bVar[] = "b";
	char * output = replaceFunc(cString, bVar);
	cout << output << "\n";
	delete[] output;
	return 0;
}
