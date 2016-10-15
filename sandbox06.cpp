#include <iostream>
#include <cstdlib>
using namespace std;

void switchFunc (int* pA, int* pB) {
	int crane = *pB;
	*pB = *pA;
	*pA = crane;
	//cout << *pA << ", " << *pB << "\n";
}

int main () {
	int numA = 2; 
	int numB = 1;
	int* pnA = &numA;
	int* pnB = &numB;
	switchFunc(pnA, pnB);
//	switchFunc((int*)numA, (int*)numB);
	cout << numA << ", " << numB << "\n";
	return 0;
}