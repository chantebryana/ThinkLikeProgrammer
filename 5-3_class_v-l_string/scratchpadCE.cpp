#include <iostream>
#include <cstdlib>

int main () {
	int fish = 5;
	int * pfish;
	pfish = & fish;
	std::cout << "            address of fish: " << & fish << std::endl;
	std::cout << "address referenced by pfish: " << pfish << std::endl;
	std::cout << "            value of fish: " << fish << std::endl;
	std::cout << "value pointed to by pfish: " << *pfish << std::endl;
	return 0;
}
