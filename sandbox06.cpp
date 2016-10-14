#include <iostream>
#include <cstdlib>
using namespace std;

void switchFunc (int* pA, int* pB) {
	int crane = *pB;
	*pB = *pA;
	*pA = crane;
	cout << *pA << ", " << *pB << "\n";
}

int main () {
	int numA = 2; 
	int numB = 1;
	switchFunc(numA, numB);
	//cout << numA << ", " << numB << "\n";
	return 0;
}