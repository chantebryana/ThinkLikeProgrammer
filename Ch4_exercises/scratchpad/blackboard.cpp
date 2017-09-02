// try to print head->next instead of head->data or address of head

void print_node_next(node * head) {
	if (head != NULL) {
		std::cout << "root->next: " << std::endl;
		std::cout << head << std::endl;
		while (head->next != 0) {
			std::cout << head->next << std::endl;
			head = head->next;
		}
		std::cout << head->next << std::endl;
	}
}
/*
// very first attempt to convert array back to linked list:
node * list_ify (node * * a_of_node_address, int size) {
	node * head_from_array = new node;
	head_from_array = a_of_node_address[0] // don't know if I need different pointer layers
	for (int i = 1; i < size; i++) {
		head_from_array->next = a_of_node_address[i];
		head_from_array = head_from_array->next;
	}
	return head_from_array;
}
*/
// very first attempt to convert array back to linked list:
node * list_ify (node * * a_of_node_address, int size) {
	std::cout << "head_from_array:" << std::endl;
	node * head_from_array = new node;
	//head_from_array = a_of_node_address[0]; // don't know if I need different pointer layers
	//std::cout << head_from_array << std::endl;
	for (int i = 1; i < size; i++) {
		head_from_array->next = a_of_node_address[i];
		std::cout << head_from_array << std::endl;
		head_from_array = head_from_array->next;
	}
	//head_from_array->next = a_of_node_address[size-1];
	head_from_array->next = NULL;
	std::cout << head_from_array << std::endl;
	return head_from_array;
}

// (temporary?) helper function: find length of array: 
// this would only work if array is null-terminated, which it may be if I have to explicitly define the null pointer at the end of linked list:
int find_array_length(node * * array) {
	int count = 0;
	while (array[count] != 0) {
		count ++;
	}
	count ++;
	return count;
}


