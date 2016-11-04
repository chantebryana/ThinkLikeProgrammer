//https://en.wikipedia.org/wiki/Function_pointer

#include <iostream>
using namespace std;

//add func
int add(int first, int second) {
	return first + second;
}

//subtract func
int subtract(int first, int second) {
	return first - second;
}

//pointer func (I think)
int operation(int first, int second, int (*funcToCall)(int, int)) {
	return (*funcToCall)(first, second);
}

int main () {
	//declare and define
	int a, b;
	int (*plus)(int, int) = add;
	int (*minus)(int, int) = subtract;
	
	//run pointer func with operations() 
	a = operation(7, 5, plus);
	b = operation(20, a, minus);
	//print the magic we created!
	cout << "a = " << a << " and b = " << b << "\n";
	return 0;
}
