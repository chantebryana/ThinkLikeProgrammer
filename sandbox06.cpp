#include <iostream>
#include <cstdlib>
using namespace std;

//switch two elements around
void switchFunc (int* pA, int* pB) {
	int crane = *pB;
	*pB = *pA;
	*pA = crane;
}

//actual sorting function: sort an array!
int * sortFunc(int *intArray, int arrayLength){
	//create if / else statement to determine if I even need to do a switch
	if (intArray[0] > intArray[1]) {
		// use switchFunc to sort the contents of intArray here
		switchFunc(&intArray[0], &intArray[1]);	
	}
	// return the intArray for obscure reasons (to make it 'pass through' the function)
	return intArray;
}

//find the smallest! but first fix the wording.
int smallest(int* array, int aLength) {
	int indexTally = 1;
	int compVar = 100; 
	int indexTrack = 0;
	for (int i = 0; i < aLength; i++) {
		for (int i = indexTally; i < aLength; i++) {
			if (compVar > array[i]) {
				compVar = array[i];
				indexTrack = i;
			}
			//indexTally++;
		}
		indexTally++;
		//return indexTrack;
		sortFunc(array, aLength);
	}
}

int main () {
	//declare and define array
	int const ALENGTH = 8;
	int a[ALENGTH] = {2, 1, 4, 3, 7, 6, 5, 9};
	//call smallest()
	smallest(a, ALENGTH);
	
	//loop to print
	for (int i = 0; i<ALENGTH; i++) {
		cout << a[i] << " ";
	}
	cout << "\n";
	return 0;
}