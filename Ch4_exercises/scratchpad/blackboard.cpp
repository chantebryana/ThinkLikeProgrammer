#include <iostream> // cin, cout
#include <cstdlib> // qsort plus much more

int main () {
	char a;
	char * b;
	char ** c;
	a = 'z';
	b = &a;
	c = &b;
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "c: " << c << std::endl;

	return 0;
}
