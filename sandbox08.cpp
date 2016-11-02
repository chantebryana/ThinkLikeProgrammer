#include <iostream>
#include <cstdlib>
using namespace std;

//switch two elements around
void switchFunc (int* pA, int* pB) {
	int crane = *pB;
	*pB = *pA;
	*pA = crane;
}

//func to compare
int compLogicFunc(int * intArray) {
	int i;
	if (intArray[i] > intArray[i+1]) {
		return 1;
	} else { 
		return 0;
	}
}

//actual sorting function: sort an array!
int * sortFunc(int *intArray, int arrayLength){
	//create a quick and dirty outer loop for the inner loop:
	for (int h = 0; h < arrayLength-1; h++) {		
		//create for loop conditional; stop one element shy of end of array, since loop compares i+1:
		int shorterVar = arrayLength - 1;
		for (int i = 0; i < shorterVar; i++) {	
			//create if / else statement to determine if I even need to do a switch
			if (compLogicFunc(intArray)) {
				// use switchFunc to sort the contents of intArray here
				switchFunc(&intArray[i], &intArray[i+1]);	
			} 
		} shorterVar --;
	}
	// return the intArray for obscure reasons (to make it 'pass through' the function)
	return intArray;
}

int main () {
	//define constants
	int const ALENGTH = 7;
	//declare and define array
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
