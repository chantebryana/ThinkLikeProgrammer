// Variable-Length String problem, TLAP Ch4
#include <cstdlib>
#include <iostream>
using namespace std;

//take a string and a number and return the character at the position in the string
void characterAt(int * array, int indexToFind) {
	cout << array[indexToFind] << "\n";
}

int main() {
	int const aLength = 5;
	int a[aLength] = {1, 2, 3, 4, 5};
	int positionIndex = 3;
	int * positionPointer = &positionIndex;
	characterAt(a, 3);
	return 0;
}
