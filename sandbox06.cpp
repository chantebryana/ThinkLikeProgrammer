#include <iostream>
#include <cstdlib>
using namespace std;

void switch (int* pA, *pB) {
	int crane = *pB;
	*pB = *pA;
	*pA = crane;
}

int main () {
	int numA = 2; 
	int numB = 1;
	switch(numA, numB);
	cout << numA << ", " << numB << "\n";
	return 0;
}