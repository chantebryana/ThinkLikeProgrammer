#include <iostream>
using namespace std;

//define comparison function for qsort
int compareFunc(const void *voidA, const void *voidB) {
	int *intA = (int *)(voidA);
	int *intB = (int *)(voidB);
	return *intA - *intB;
}

int main () {
	//sort the unsorted responses with qsort; use compareFunc defined above 
	qsort(array, length, sizeof(int), compareFunc);
	
	return 0;
}