#include <iostream>
#include <cstdlib>
using namespace std;

int smallest(int* array) {
	int compVar = 100; //this is a number larger than anything in the array
	int indexTrack = 0; //this tracks the index of the smallest value
	for (int i = 0; i < 3; i++) { //i starting at 0 will actually depend on indexTally; 3 is the size of the array defined in main
		if (compVar > array[i]) {
			compVar = array[i];
			indexTrack = i;
		}
	}
	return indexTrack;
}

int main() {
	int a[3] = {1, 2, 3};
	cout << a[smallest(a)] << "\n";
	return 0;
}