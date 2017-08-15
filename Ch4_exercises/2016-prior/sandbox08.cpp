#include <iostream>
#include <cstdlib>
using namespace std;

//switch two elements around
void switchFunc (int* pA, int* pB) {
	int crane = *pB;
	*pB = *pA;
	*pA = crane;
}

// func to compare; 1 is "true", 0 is "false"
// http://www.cplusplus.com/reference/cstdlib/qsort/ 
int compLogicFunc(const void * a, const void * b) {
	if ( *(int*)a > *(int*)b ) {
		return 1;
	} else {
		return 0;
	}
}

// pointer func
// http://www.cplusplus.com/reference/cstdlib/qsort/ 
// https://en.wikipedia.org/wiki/Function_pointer
int compPointFunc (const void * p1, const void * p2, int (*funcToCall)(const void *, const void *));

/*
int pointFunc(int * first, int * second, int (*funcToCall)(int *, int *)) {
	return (*funcToCall)(first, second);
}

//function passed as argument in sortFunc
int argFunc (int * a, int * b, int (*funcToCall)(int* , int *)) {
	return (*funcToCall)(a, b);
}
*/

/*
Bubble Sort Func: nested loops make sure the function compares and sorts the entire array; shorterVar removes comparing elements at the end that are already in their proper place; black boxes like compLogicFunc and switchFunc make the various pieces separate and more generalized; return intArray to pass the sorted array onwards.
*/ 
int * sortFunc(int *intArray, int arrayLength, compPointFunc){
	for (int h = 0; h < arrayLength-1; h++) {		
		int shorterVar = arrayLength - 1; 
		for (int i = 0; i < shorterVar; i++) {	
			if (compPointFunc) {
				switchFunc(&intArray[i], &intArray[i+1]);	
			} 
		} shorterVar --;
	}
	return intArray;
}

int main () {
	//define constants, array
	int const ALENGTH = 5;
	int a[ALENGTH] = {5, 4, 3, 2, 1};
	//call sortFunc() 
	sortFunc(a, ALENGTH, compLogicFunc);
	
	//loop to print
	for (int i = 0; i<ALENGTH; i++) {
		cout << a[i] << " ";
	}
	cout << "\n";
	return 0;
}
