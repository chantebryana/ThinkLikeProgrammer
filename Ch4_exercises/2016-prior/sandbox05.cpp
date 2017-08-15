#include <iostream>
#include <cstdlib>
using namespace std;

int main () {
	//declaring array, pointers
	int a[2] = {2, 1};
	int *p0 = &a[0]; //declare and define pointer 
	int *p1 = &a[1]; //declare and define pointer 
	
	//printing it out
	cout << *p0 << " " << *p1 << " \n"; //prints "value pointed to by p0, p1"
	
	return 0;
}