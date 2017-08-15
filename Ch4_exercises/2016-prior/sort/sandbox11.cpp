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

//sort evens first descending, then odds ascending
//1 is "true", 0 is "false"
int evenOddBrain(const void * a, const void * b) {
	int * numA = (int *)a;
	int * numB = (int *)b;
	if (* numA % 2 == 0) {					//if first element's even
		if (* numB % 2 == 0) {				//if second element's even
			if (* numA < * numB) {			//if first element's larger than second
				return 1;
			} else {								//if first element's smaller than second
				return 0;
			}
		} else if (* numB % 2 == 1) {		//if second element's odd
			return 0;
		}
	} else if (* numA % 2 == 1) {			//if first element's odd
		if (* numB % 2 == 1) {				//if second element's odd
			if (* numA > * numB) {			//if first element's larger than second
				return 1;
			} else {								//if first element's smaller than second
				return 0;
			}
		} else if (* numB % 2 == 0) {		//if second element's even
			return 1;
		}
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
	int const LENGTH = 9;
	int values[LENGTH] = {2, 7, 8, 3, 6, 4, 5, 9, 1};
	qsort(values, LENGTH, sizeof(int), evenOddBrain);
	printIt(values, LENGTH);

	return 0;
}
