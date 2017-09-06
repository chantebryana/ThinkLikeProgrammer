#include <iostream> // cin, cout
#include <cstdlib> // qsort plus much more

struct node {
	int data;
	node * next;
} ;

void process_user_input (node * * head);
void insert_new_at_front(node * * head, int user_input);
int find_list_length(node * head);
node * * array_ify(node * head, int * size_buff);
void print_node(node * head);
void print_address(node * head);
// void print_node_next(node * head);
node * list_ify(node * * a_nn, int s);
void print_array(node * * array, const int a_length);
int compare_node(const void * void_a, const void * void_b);
void deallocate(node * * head);

int main () {
	// set root to NULL; will be populated via user-input:
	node * root = NULL;

	// this section: have user dynamically populate the linked list pointed to by root, and print out the results (value of data and address of each node) onto the console: 
	process_user_input(& root);
	print_node(root);
	print_address(root);

	// this section: save the addresses of each node to an array; function uses size buffer (the value of which will be assigned within function and is dynamic depending on the length of linked list) and returns the array of addresses: 
	int size_buff;
	node * * array_of_node_address = array_ify(root, & size_buff);

	// print out the results onto the console: 
	print_array(array_of_node_address, size_buff);

	// Jim's manual swap:
	node * temp = array_of_node_address[0];
	array_of_node_address[0] = array_of_node_address[size_buff-1];
	array_of_node_address[size_buff-1] = temp;

	// array-to-linked-list:
	std::cout << "__ARRAY-TO-LINKED-LIST__" << std::endl;
	root = list_ify(array_of_node_address, size_buff);
	print_node(root);
	print_address(root);

	// sort contents of root using qsort and array_of_node_address; apply change to root and print out results:
	qsort(array_of_node_address, size_buff, sizeof(node *), compare_node);
	root = list_ify(array_of_node_address, size_buff);
	print_array(array_of_node_address, size_buff);
	print_node(root);

	// deallocate heap memory: 
	deallocate(& root);
	return 0;
}






// take user input (new_data) and assign it as a new node at the front of the linked list (head; by calling insert_new_at_front), creates end statement or error statements as needed (non-zero integers are valid inputs, chars end the user input loop): 
void process_user_input(node * * head) {
	std::cout << "__ADD DATA TO LINKED LIST \'ROOT\'__" << std::endl;
	std::cout << "enter a series of non-zero integers; enter a char to quit: " << std::endl;
	int quit = 0;
	int new_data;
	while (!quit) {
		std::cin >> new_data;
		if (new_data != 0) {
			insert_new_at_front(head, new_data);
		} else if (new_data == 0) {
			std::cout << "all done!" << std::endl;
			quit = 1;
		} else {
			std::cout << "input error" << std::endl;
			quit = 1;
		}
	}
}

// inserts new node at front of linked list; called within process_user_input: 
void insert_new_at_front(node * * head, int user_input) {
	node * temp = new node;
	temp->data = user_input;
	temp->next = * head;
	* head = temp;
}

// finds the length of linked list, to be used in array_ify (iterates through each node of linked list, increasing the counter one by one until reaching the end of the list): 
int find_list_length(node * head) {
	int counter = 0;
	while (head->next != NULL) {
		counter += 1;
		head = head->next;
	}
	counter += 1;
	return counter;
}

// save memory addresses of each linked list node into an array on the heap: 
node * * array_ify(node * head, int * size_buff) {
	// dynamically find the value of size_buff, based on the length of the linked list: 
	* size_buff = find_list_length(head);

	// create a new heap array, then populate it with the addresses of each node in linked list: 
	node * * a_of_node_address = new node * [* size_buff];
	for (int i = 0; i < * size_buff; i++) {
		a_of_node_address[i] = head;
		head = head->next;
	}
	// return array of node addresses back to use in main: 
	return a_of_node_address;
}

// prints the data contained within linked list head (iterates through each node of linked list, printing each head->data to the console one by one until reaching the end of the list): 
void print_node(node * head) {
	if (head != NULL) {
		std::cout << "data: ";
		while (head->next != 0) {
			std::cout << head->data << " ";
			head = head->next;
		}
		std::cout << head->data << std::endl;
	}
}

// prints the address of each node within the linked list head (iterates through each node of linked list, printing the address/reference of each node to the console one by one until reaching the end of the list): 
void print_address(node * head) {
	if (head != NULL) {
		std::cout << "data addresses: " << std::endl;
		while (head->next != 0) {
			std::cout << head << std::endl;
			head = head->next;
		}
		std::cout << head << std::endl;
	}
}

/*
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
*/

// take memory addresses saved in array and assign to head and node->next of linked list:
node * list_ify(node * * a_nn, int s) {
	node * next_a;
	next_a = a_nn[0];
	for (int i = 1; i < s; i++) {
		next_a->next = a_nn[i];
		next_a = next_a->next;
	}
	next_a->next = NULL;
	return a_nn[0];
}

// prints each element of array to console: 
void print_array(node * * array, const int a_length) {
	std::cout << std::endl << "address_of[i]: " << std::endl;
	for (int i = 0; i < a_length; i++) {
		std::cout << array[i] << std::endl;
	}
}

// comparison function to be used within qsort. using memory addresses stored in array, points to nodes of linked list and decides whether to rearrange them or not: 
int compare_node(const void * void_a, const void * void_b) {
	node * * prev = (node * *)void_a;
	node * * next = (node * *)void_b;
	if (((*prev)->data) < ((*next)->data)) {
		return -1;
	} else if (((*prev)->data) > ((*next)->data)) {
		return 1;
	} else { // prev->data == next->data
		return 0;
	}
}

// deallocate heap memory used up by linked list head: 
void deallocate(node * * head) {
	while (* head) {
		node * temp;
		temp = * head;
		* head = (* head)->next;
		delete temp;
	}
}
