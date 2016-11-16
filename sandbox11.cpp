// http://www.cplusplus.com/reference/cstdlib/qsort/ 
#include <cstdlib>
#include <iostream>
using namespace std;

//comparison func
int compareInt(const void * a, const void * b) {
	if ( *(int *)a > *(int *)b ) {
		return 1;
	} else {
		return 0;
	}
}

//print the array!
void printIt(int * value, int length) {
	for (int i = 0; i < length; i++) {
		cout << value[i] << " ";
	}
	cout << "\n";
}

int main () {
	int const LENGTH = 6;
	int values[LENGTH] = {40, 10, 100, 90, 20, 25};
	qsort(values, LENGTH, sizeof(int), compareInt);
	printIt(values, LENGTH);

	return 0;
}
