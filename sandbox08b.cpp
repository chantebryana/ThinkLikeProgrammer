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

void bubbleNest(int *intArray, int arrayLength) {
	int shorterVar = arrayLength - 1;
	for (int i = 0; i < shorterVar; i++) {
		if (compLogicFunc (&intArray[i], &intArray[i+1])) {
				switchFunc(&intArray[i], &intArray[i+1]);	
		} 
	} shorterVar --;
}

// Bubble Sort Func
int * sortFunc(int *intArray, int arrayLength){
	for (int h = 0; h < arrayLength-1; h++) {		
		bubbleNest(intArray, arrayLength);
	}
	return intArray;
}

int main () {
	//define constants, array
	int const ALENGTH = 7;
	int a[ALENGTH] = {2, 8, 6, 4, 5, 9, 1};
	//call sortFunc() 
	sortFunc(a, ALENGTH);
	
	//loop to print
	for (int i = 0; i<ALENGTH; i++) {
		cout << a[i] << " ";
	}
	cout << "\n";
	return 0;
}

