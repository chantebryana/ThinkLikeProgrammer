#include <iostream> // cin, cout
#include <cstdlib> // qsort plus much more

struct node {
	int data;
	node * next;
} ;

void process_user_input (node * * head);
void insert_new_at_front(node * * head, int user_input);
int find_list_length(node * head);
void node_address_to_array (node * head, node * * array, const int a_length);
//node * * array_ify(node * head, int * size_buff);
void print_node(node * head);
void print_address(node * head);
void print_array(node * * array, const int a_length);
void deallocate(node * * head);

int main () {
	node * root = new node;
	root->data = 7;
	root->next = NULL;

	print_node(root);

	// this section: have user dynamically populate the linked list pointed to by root, and print out the results onto the console: 
	std::cout << "__ADD DATA TO LINKED LIST \'ROOT\'__" << std::endl;
	std::cout << "enter a series of non-zero integers; enter a char to quit: " << std::endl;
	process_user_input(& root);
	print_node(root);
	print_address(root);

	// this section: save the addresses of each node pointer to an array, using a dynamic array length variable: 
	const int A_LGTH = find_list_length(root);
	std::cout << "linked list length: " << A_LGTH << std::endl;
	node * * address_of = new node * [A_LGTH];
	node_address_to_array(root, address_of, A_LGTH);

	// int size_buff
	// node * * array_of_node_address[] = array_ify(root, & size_buff);

	// print out the results onto the console: 
	print_array(address_of, A_LGTH);
	// print_array(array_of_node_address, size_buff);

	// deallocate heap memory: 
	delete[] address_of; // CE nu-uh
	deallocate(& root);
	return 0;
}







void process_user_input(node * * head) {
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

void insert_new_at_front(node * * head, int user_input) {
	node * temp = new node;
	temp->data = user_input;
	temp->next = * head;
	* head = temp;
}

int find_list_length(node * head) {
	int counter = 0;
	while (head->next != NULL) {
		counter += 1;
		head = head->next;
	}
	counter += 1;
	return counter;
}

void node_address_to_array (node * head, node * * array, const int a_length) {
	for (int i = 0; i < a_length; i++) {
		array[i] = head; 
		head = head->next;
	}
}

/*
// save memory addresses of each linked list node into an array on the heap: 
node * * array_ify(node * head, int * size_buff) {
	// dynamically find the value of size_buff, based on the length of the linked list: 
	* size_buff = find_list_length(head);

	// create a new heap array, then populate it with the addresses of each node in linked list: 
	node * * a_of_node_address = new node * [* size_buff];
	for (int i = 0; i < * size_buff, i++) {
		a_of_node_address[i] = head;
		head = head->next;
	}
	// return array of node addresses back to use in main: 
	return a_of_node_address;
}
*/

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

void print_array(node * * array, const int a_length) {
	std::cout << std::endl << "address_of[i]: " << std::endl;
	for (int i = 0; i < a_length; i++) {
		std::cout << array[i] << std::endl;
	}
}

void deallocate(node * * head) {
	while (* head) {
		node * temp;
		temp = * head;
		* head = (* head)->next;
		delete temp;
	}
}
