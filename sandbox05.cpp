#include <iostream>
#include <cstdlib>
using namespace std;

int main () {
	//declaring array, pointers
	int a[2] = {2, 1};
	int *p0 = &a[0];
	int *p1 = &a[1];
	
	//printing it out
	cout << p0 << " " << p1 << " \n";
	
	return 0;
}