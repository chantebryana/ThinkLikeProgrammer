#include <iostream>
using namespace std;

// adding func
// http://www.cplusplus.com/forum/windows/32209/
int add(int * array, int length){
	int sum = 0;
	for (int i = 0; i < length; i++) {
		sum += array[i];
	}
	return sum;
}

// attempt at pointer func
// https://en.wikipedia.org/wiki/Function_pointer
int pFunc(int * arrPoint, int length, int (*funcToCall)(int *, int)) {
	return (*funcToCall)(arrPoint, length);
}

int main () {
	const int ALENGTH = 4;
	int a[ALENGTH] = {4, 3, 2, 1};
	//attempt at pointer func...
	int b = pFunc(a, ALENGTH, add);
	cout << b << "\n";
	return 0;
}
