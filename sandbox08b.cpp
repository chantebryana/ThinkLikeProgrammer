#include <iostream>
#include <cstdlib>
using namespace std;

//switch two elements around
void switchFunc (int* pA, int* pB) {
	int crane = *pB;
	*pB = *pA;
	*pA = crane;
}

//func to compare; 1 is "true", 0 is "false"z
int compLogicFunc(int * intArrayA, int * intArrayB) {
	if (* intArrayA > * intArrayB) {
		return 1;
	} else { 
		return 0;
	}
}

//1 is "true", 0 is "false"
int evenOddBrain(int * numA, int * numB) {
	if (numA % 2 == 0) {					//if first element's even
		if (numB % 2 == 0) {				//if second element's even
			if (numA > numB) {			//if first element's larger than second
				return 1;
			} else {							//if first element's smaller than second
				return 0;
			}
		} else if (numB % 2 == 1) {	//if second element's odd
			return 0;
		}
	} else if (numA % 2 == 1) {		//if first element's odd
		if (numB % 2 == 1) {				//if second element's odd
			if (numA > numB) {			//if first element's larger than second
				return 1;
			} else {							//if first element's smaller than second
				return 0;
			}
		} else if (numB % 2 == 0) {	//if second element's even
			return 1;
		}
	}
}

void bubbleNest(int *intArray, int arrayLength, int (*compPointer)(int *, int *)) {
	int shorterVar = arrayLength - 1;
	for (int i = 0; i < shorterVar; i++) {
		if ( (*compPointer)(&intArray[i], &intArray[i+1]) ) { 
			   jswitchFunc(&intArray[i], &intArray[i+1]);	
		} 
	} shorterVar --;
}

// Bubble Sort Func
int * sortFunc(int *intArray, int arrayLength, int (*compPointer)(int *, int *)){
	for (int h = 0; h < arrayLength-1; h++) {		
		bubbleNest(intArray, arrayLength, compPointer);
	}
	return intArray;
}

int main () {
	//define constants, array
	int const ALENGTH = 9;
	int a[ALENGTH] = {2, 7, 8, 3, 6, 4, 5, 9, 1};
	//call sortFunc() 
	sortFunc(a, ALENGTH, evenOddBrain);
	
	//loop to print
	for (int i = 0; i<ALENGTH; i++) {
		cout << a[i] << " ";
	}
	cout << "\n";
	return 0;
}

