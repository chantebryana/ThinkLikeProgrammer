void print_array(int * * array, const int a_length) {
	std::cout << std::endl << "address_of[i]: " << std::endl;
	for (int i = 0; i < a_length; i++) {
		std::cout << array[i] << std::endl;
	}
}

//	===	===	===
// raw code: 
	std::cout << "address_of[i]: " << std::endl;
	for (int i = 0; i < SOME_NUM; i++) {
		std::cout << address_of[i] << std::endl;
	}
