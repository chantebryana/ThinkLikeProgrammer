#include <iostream> // cin, cout
#include <cstdlib> // qsort plus much more

struct node {
	int data;
	node * next;
} ;

void process_user_input (node * * head, int new_data);
void insert_new_at_front(node * * head, int user_input);
int find_length_linked_list(node * head);
void node_address_to_array (node * head, int * * array, const int a_length);
void print_node(node * head);
void print_address(node * head);
void print_array(int * * array, const int a_length);
void deallocate(node * * head);

int main () {
	node * root = new node;
	root->data = 7;
	root->next = NULL;

	print_node(root);

	// this section: have user dynamically populate the linked list pointed to by root, and print out the results onto the console: 
	int user_input;
	std::cout << "__ADD DATA TO LINKED LIST \'ROOT\'__" << std::endl;
	std::cout << "enter a series of non-zero integers; enter a char to quit: " << std::endl;
	process_user_input(& root, user_input);
	print_node(root);
	print_address(root);

	const int A_LGTH = find_length_linked_list(root);
	std::cout << "linked list length: " << A_LGTH << std::endl;

	// this section: save the addresses of each node pointer to an array: 
	const int SOME_NUM = 10; // CE: static number for now: hope to make this dynamic in the near future (use buffer?)
	//int * * address_of = new int * [SOME_NUM];
	int * * address_of = new int * [A_LGTH];
	//node_address_to_array(root, address_of, SOME_NUM);
	node_address_to_array(root, address_of, A_LGTH);

	// print out the results onto the console: 
	// CE: address of last node (7, defined on line 17) changes on each printout: ???
	//print_array(address_of, SOME_NUM);
	print_array(address_of, A_LGTH);

	// deallocate heap memory: 
	delete[] address_of;
	deallocate(& root);
	return 0;
}







void process_user_input(node * * head, int new_data) {
	int quit = 0;
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
	temp = NULL;
}

int find_length_linked_list(node * head) {
	int counter = 0;
	while (head->next != NULL) {
		counter += 1;
		head = head->next;
	}
	counter += 1;
	return counter;
}

void node_address_to_array (node * head, int * * array, const int a_length) {
	node * temp = head;
	for (int i = 0; i < a_length; i++) {
		array[i] = &temp->data;
		// if linked list ends before array loop, break out: 
		if (temp->next == NULL) {break;}
		temp = temp->next; // or (*temp).next
	}
	temp = NULL;
}

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
			std::cout << (& head->data) << std::endl;
			head = head->next;
		}
		std::cout << (& head) << std::endl;
	}
}

void print_array(int * * array, const int a_length) {
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
