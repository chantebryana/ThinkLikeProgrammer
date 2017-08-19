#include <iostream> // cin, cout
#include <cstdlib> // qsort plus much more

int * assign_array() {
	//int array[] = {1, 2, 3, 4, 5};
	int * array = new int[5];
	int j = 0;
	for (int i = 0; i < 5; i++) {
		j++;
		array[i] = j;
	}
	return array;
}


int main() {
	//int length = 5;
	//int array[] = {1, 2, 3, 4, 5};
	//int copy = array;
	//int copy[] = array;
	//int copy[5] = array;
	//int * copy = array;
	int * copy = assign_array();
/*	
	int copy[5] = {};
	for (int i = 0; i < 5; i++) {
		copy[i] = array[i];
	}
*/
	for (int i = 0; i < 5; i++) {
		std::cout << copy[i] << " ";
	}
	std::cout << std::endl;

	return 0;
}
