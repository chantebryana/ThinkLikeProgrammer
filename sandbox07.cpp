#include <iostream>
#include <cstdlib>
using namespace std;

int smallest(int array) {
	int* compVar = 0;
	for (int i = 0; i < 3; i++) {
		if (*compVar < array[i]) {
			*compVar = array[i];
		}
	}
	return *compVar;
}

int main() {
	int a[3] = {3, 1, 2};
	cout << smallest(a) << "\n";
	return 0;
}