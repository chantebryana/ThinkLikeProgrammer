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

