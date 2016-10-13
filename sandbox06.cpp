#include <iostream>
#include <cstdlib>
using namespace std;

void switchFunc (int* pA, int* pB) {
	int crane = *pB;
	*pB = *pA;
	*pA = crane;
}

int main () {
	int numA = 2; 
	int numB = 1;
	int* pnA = numA;
	int* pnB = numB;
	switchFunc(pnA, pnB);
	cout << pnA << ", " << pnB << "\n";
	return 0;
}