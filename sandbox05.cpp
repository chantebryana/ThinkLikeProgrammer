#include <iostream>
#include <cstdlib>
using namespace std;

int main () {
	//declaring array, pointers
	int a[2] = {2, 1};
	int *p0 = a[0];
	int *p1 = a[1];

	//attempt at sorting func 
	int sort(int *a) {
		if (a[0] > a[1])
			p0 = a[1];
			p1 = a[0];
		return &p0, &p1;
	}
	cout << sort(a) << "\n";
	
	return 0;
}