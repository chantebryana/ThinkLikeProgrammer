//https://en.wikipedia.org/wiki/Function_pointer

#include <iostream>
using namespace std;

int add(int first, int second) {
	return first + second;
}

int subtract(int first, int second) {
	return first - second;
}

int operation(int first, int second, int (*funcToCall)(int, int)) {
	return (*funcToCall)(first, second);
}

int main () {
	int a, b;
	int (*plus)(int, int) = add;
	int (*minus)(int, int) = subtract;
	
	a = operation(7, 5, plus);
	b = operation(20, a, minus);
	cout << "a = " << a << " and b = " << b << ".\n";
	return 0;
}
