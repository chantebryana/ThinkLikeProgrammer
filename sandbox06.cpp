#include <iostream>
#include <cstdlib>
using namespace std;

/*
void sort(int *a, int *p0, int *p1) {
	if (a[0] > a[1]) {
		p0 = &a[1];
		p1 = &a[0];
	}
}
*/

int main () {
	//declaring array, pointers
	int a[2] = {2, 1};
	int *pa = a;
	int b[2] = {0, 0};
	int *pb = b;
	int *p0 = &pa[0]; //declare and define pointer 
	int *p1 = &pa[1]; //declare and define pointer 
	
	//sorting???
	int counter = 0;
	if (pa[0] > pa[1]) {
		b[0] = pa[1];
		b[1] = pa[0];
	}
	pa = b;
	
	p0 = &pa[0]; //declare and define pointer 
	p1 = &pa[1]; //declare and define pointer 
	
	//calling sorting function
	//sort(*a, p0, p1);
	
	//printing it out
	cout << *p0 << " " << *p1 << " \n"; //prints "value pointed to by p0, p1"
	
	return 0;
}