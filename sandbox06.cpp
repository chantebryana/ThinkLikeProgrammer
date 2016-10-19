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
	int* a;
	switchFunc((a+0 * sizeof(int)), (a+1 * sizeof(int)));
	// return the intArray for obscure reasons (to make it 'pass through' the function)
	return intArray;
}

int main () {
	//declare and define array
	int a[2] = {2, 1};
	//call sortFunc() 
	sortFunc(a, 2);
	
	//loop to print
	for (int i = 0; i<2; i++) {
		cout << a[i] << " ";
	}
	cout << "\n";
	return 0;
}