#include <iostream>
using namespace std;

int add(int * array, int length){
	int sum = 0;
	for (int i = 0; i < length; i++) {
		sum += array[i];
	}
	return sum;
}

int main () {
	const int ALENGTH = 4;
	int a[ALENGTH] = {4, 3, 2, 1};
	return 0;
}
