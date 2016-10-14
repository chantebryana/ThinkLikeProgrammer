#include <iostream>
#include <cstdlib>
using namespace std;

void switchFunc (void* pA, void* pB) {
	int* intA = (int *)pA;
	int* intB = (int *)pB;
	int crane = *intB;
	*intB = *intA;
	*intA = crane;
	cout << *intA << ", " << *intB << "\n";
}

int main () {
	int numA = 2; 
	int numB = 1;
	switchFunc(numA, numB);
	//cout << numA << ", " << numB << "\n";
	return 0;
}