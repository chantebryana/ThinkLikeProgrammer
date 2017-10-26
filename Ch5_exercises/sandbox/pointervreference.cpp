// diving deeper into passing by pointer compared with / against passing by reference
// http://www.geeksforgeeks.org/passing-by-pointer-vs-passing-by-reference-in-c/

//C++ program to demonstrate differences btwn pointer and reference

#include<iostream>

struct demo {
	int a;
} ;

int main () {
	int x = 5;
	int y = 6;
	demo d;
	//std::cout << "d " << d << std::endl;

	int *p;
	p = &x; 				// returns 0x7ffe7e1c2d50
	std::cout << "p = &x; " << p << std::endl;
	p = &y; 				// 1. pointer reintialization a; returns 0x7ffe7e1c2d54
	std::cout << "p = &y; " << p << std::endl;
	int &r = x;
	// &r = y;			// 1. compile error
	r = y;					// 1. y value becomes 6
	std::cout << "r = y; " << r << std::endl;

	p = NULL;
	// &r = NULL;		// 2. compile error

	p++;						// 3. points to next memory location
	std::cout << "p++; " << p << std::endl;
	r++;						// 3. x value becomes 7
	std::cout << "r++; " << r << std::endl;

	std::cout << &p << " " << &x << std::endl;	// 4. Different address
	std::cout << &r << " " << &x << std::endl; 	// 4. same address

	demo *q = &d;
	demo &qq = d;

	q->a = 8;
	// q.a = 8;			// 5. Compile error
	qq.a = 8;
	// qq->a = 8;		// 5. Compile error

	std::cout << q->a << std::endl;	// 6. prints the address
	std::cout << qq.a << std::endl;	// 6. prints the value of x

	return 0;
}
