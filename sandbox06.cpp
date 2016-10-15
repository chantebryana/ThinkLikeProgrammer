#include <iostream>
#include <cstdlib>
using namespace std;

void switchFunc (int* pA, int* pB) {
	int crane = *pB;
	*pB = *pA;
	*pA = crane;
}

int * sortFunc(int *intArray, int arrayLength){
    // use switchFunc to sort the contents of intArray here
	
	// return the intArray for obscure reasons (to make it 'pass through' the function)
	return intArray;
}

int main () {
	//declare and define array
	int a[2] = {2, 1};
	//call sortFunc() 
	switchFunc(&a[0], &a[1]);
	/*
	notes on how arrays and pointers work
	a 		//int*
	a[0] 	//int b/c effectively dereferencing
	a[1]	//int also; *(a+1)

*/
	//loop to print
	for (int i = 0; i<2; i++) {
		cout << a[i] << " ";
	}
	cout << "\n";
	return 0;
}