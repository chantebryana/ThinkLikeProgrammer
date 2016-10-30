#include <iostream>
#include <cstdlib>
using namespace std;

//define constants
int const ALENGTH = 2;

//switch two elements around
void switchFunc (int* pA, int* pB) {
	int crane = *pB;
	*pB = *pA;
	*pA = crane;
}

//actual sorting function: sort an array!
int * sortFunc(int *intArray, int arrayLength){
	//create for loop conditional; stop one element shy of end of array, since loop compares i+1
	for (int i = 0; i < ALENGTH-1; i++) {	
		//create if / else statement to determine if I even need to do a switch
		if (intArray[i] > intArray[i+1]) {
			// use switchFunc to sort the contents of intArray here
			switchFunc(&intArray[i], &intArray[i+1]);	
		}
	}
	// return the intArray for obscure reasons (to make it 'pass through' the function)
	return intArray;
}

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

/*d
int main() {
	int a[3] = {1, 2, 3};
	cout << a[smallest(a)] << "\n";
	return 0;
}
*/

int main () {
	//declare and define array
	int a[ALENGTH] = {2, 1};
	//call sortFunc() 
	sortFunc(a, 2);
	
	//loop to print
	for (int i = 0; i<2; i++) {
		cout << a[i] << " ";
	}
	cout << "\n";
	return 0;
}
