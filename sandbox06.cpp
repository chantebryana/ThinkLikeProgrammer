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
    // use switchFunc to sort the contents of intArray here
	switchFunc((intArray+0), (intArray+1));
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