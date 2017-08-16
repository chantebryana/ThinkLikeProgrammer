#include <iostream> // cin, cout
#include <cstdlib> // qsort plus much more

struct node {
	int data;
	node * next;
} ;

void process_user_input (node * * head, int new_data);
void insert_new_at_front(node * * head, int user_input);
void print_node(node * head);
void print_address(node * head);
void deallocate(node * * head);

int main () {
	node * root = new node;
	root->data = 7;
	root->next = NULL;

	print_node(root);

	int user_input;
	std::cout << "__ADD DATA TO LINKED LIST \'ROOT\'__" << std::endl;
	std::cout << "enter a series of non-zero integers; enter a char to quit: " << std::endl;
	process_user_input(& root, user_input);
	print_node(root);
	print_address(root);

	deallocate(& root);
	return 0;
}







void process_user_input (node * * head, int new_data) {
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

void deallocate(node * * head) {
	while (* head) {
		node * temp;
		temp = * head;
		* head = (* head)->next;
		delete temp;
	}
}
