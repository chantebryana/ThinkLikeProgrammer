// JE's instruction on how to turn reverse func into stack memory: 
//int * reverse(int * a) {
void reverse(int * a) {
	int a_length = 5;
	int placeholder[5];
	int j = a_length-1
	for (int i = 0; i < a_length; i ++) {
		placeholder[i] = a[j];
		j--;
	}
	//a = placeholder;
	for (int i = 0; i < a_length; i ++) {
		a[i] = placeholder[i];
	}
	//return a;
}

int main() {
	int my_array[5] = {1, 2, 3, 4, 5};
	reverse(my_array);
	for (int i = 0; i < a_length; i ++) {
		std::cout << my_array[i];
	}
	std::cout << std::endl;
	return 0;
}

// CE's heap pointer reverse func:
//void reverse(int * a, int * b) {
void reverse_int(int * * a) {
	int a_length = 5;
	//int rev_a[5];
	int * rev_a = new int[5];
	int j = a_length-1;
	for (int i = 0; i < a_length; i ++) {
		rev_a[i] = (* a)[j];
		//std::cout << rev_a[i] << ", ";
		j--;
	}
	//std::cout << std::endl;
	delete[] * a;
	* a = rev_a;
}

int main () {
	//int array[5] = {1, 2, 3, 4, 5};
	//int a_b[5];
	int * array = new int[5];
	array[0] = 1; array[1] = 2; array[2] = 3; array[3] = 4; array[4] = 5; 
	//reverse_int(array, a_b);
	//reverse_int(& array);
/*
	for (int i = 0; i < 5; i++) {
		//std::cout << a_b[i];
		std::cout << array[i];
	}
	std::cout << std::endl;
*/
	delete[] array;
	return 0;
}
