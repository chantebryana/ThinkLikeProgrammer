#include <iostream>
#include <cstdlib>
using namespace std;

//switch two elements around
void switchFunc (int* pA, int* pB) {
	int crane = *pB;
	*pB = *pA;
	*pA = crane;
}

//func to compare; 1 is "true", 0 is "false"
int compLogicFunc(int * intArrayA, int * intArrayB) {
	if (* intArrayA > * intArrayB) {
		return 1;
	} else { 
		return 0;
	}
}

/*
Bubble Sort Func: nested loops make sure the function compares and sorts the entire array; shorterVar removes comparing elements at the end that are already in their proper place; black boxes like compLogicFunc and switchFunc make the various pieces separate and more generalized; return intArray to pass the sorted array onwards.
*/ 
int * sortFunc(int *intArray, int arrayLength){
	for (int h = 0; h < arrayLength-1; h++) {		
		int shorterVar = arrayLength - 1; 
		for (int i = 0; i < shorterVar; i++) {	
			if (compLogicFunc (&intArray[i], &intArray[i+1])) {
				switchFunc(&intArray[i], &intArray[i+1]);	
			} 
		} shorterVar --;
	}
	return intArray;
}

int main () {
	//define constants, array
	int const ALENGTH = 5;
	char a[ALENGTH] = {"k", "a", "b", "z", "g"};
	//call sortFunc() 
//	sortFunc(a, ALENGTH);
	
	//loop to print
	for (int i = 0; i<ALENGTH; i++) {
		cout << a[i] << " ";
	}
	cout << "\n";
	return 0;
}
