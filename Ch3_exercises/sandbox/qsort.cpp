#include <iostream> // cin, cout
#include <cstdlib> 

int compare_func(const void * void_a, const void * void_b);
int compare_char(const void * void_a, const void * void_b);
int compare_float(const void * void_a, const void * void_b);
void print_int_array(int * * a, const int a_lgth);
void print_char_array(char * a, const int a_lgth);
void print_float_array(float * a, const int a_lgth);

int main() {
	const int ARRAY_SIZE = 4;
	//int int_array[ARRAY_SIZE] = {5, 111, -86, 84};
	int * * int_array = new int * [ARRAY_SIZE];
	* int_array[0] = 5; * int_array[1] = 111; * int_array[2] = -86; * int_array[3] = 84; 
	qsort(int_array, ARRAY_SIZE, sizeof(int), compare_func);
	print_int_array(int_array, ARRAY_SIZE);

	char char_array[ARRAY_SIZE] = {'z', 'y', 'c', 't'};
	qsort(char_array, ARRAY_SIZE, sizeof(char), compare_char);
	print_char_array(char_array, ARRAY_SIZE);

	float float_array[ARRAY_SIZE] = {1.2, 99.6, 3.14, 0.4751};
	qsort(float_array, ARRAY_SIZE, sizeof(float), compare_float);
	print_float_array(float_array, ARRAY_SIZE);

	delete[] int_array;
	return 0;
}







int compare_func(const void * void_a, const void * void_b) {
	int * int_a = (int *)void_a;
	int * int_b = (int *)void_b;
	return * int_a - * int_b;
}

int compare_char(const void * void_a, const void * void_b) {
	char * char_a = (char *)void_a;
	char * char_b = (char *)void_b;
	return * char_a - * char_b;
}

int compare_float(const void * void_a, const void * void_b) {
	float * float_a = (float *)void_a;
	float * float_b = (float *)void_b;
	if ( (* float_a) < (* float_b) ) {
		return -1;
	} else if ( (* float_a) > (* float_b) ) {
		return 1;
	} else { // if ( (* float_a) == (* float_b) )
		return 0;
	}
}

void print_int_array (int * * a, const int a_lgth) {
	for (int i = 0; i < a_lgth; i++){
		std::cout << a[i] << " ";
	}
	std::cout << std::endl;
}

void print_char_array(char * a, const int a_lgth) {
	for (int i = 0; i < a_lgth; i++) {
		std::cout << a[i] << " ";
	}
	std::cout << std::endl;
}

void print_float_array(float * a, const int a_lgth) {
	for (int i = 0; i < a_lgth; i++){
		std::cout << a[i] << " ";
	}
	std::cout << std::endl;
}
