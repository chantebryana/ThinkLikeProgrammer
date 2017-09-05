#include <iostream> // cin, cout
#include <cstdlib> // qsort plus much more

struct node {
	int data;
	node * next;
} ;

// void insert_new_at_front(node * * head, int * a, int length);
void print_node(node * head);
void insert_new_at_front(node * * head, int * a, int s);
node * * node_next_to_array (node * head, int s);
void print_node_next(node * head);
void print_array(node * * a, int s);
void deallocate(node * * head);

int main () {
	int size = 6;
	int array[size] = {1,2, 3, 4, 5, 6};
	node * root = new node;
	root->data = 0;
	root->next = NULL;

	//std::cout << & root << std::endl;
	//std::cout << root << std::endl;
	//std::cout << root->data << std::endl;
	//std::cout << root->next << std::endl;

	insert_new_at_front(& root, array, size);
	print_node(root);
	print_node_next(root);
	node * * array_of_node_next = node_next_to_array(root, size);
	print_array(array_of_node_next, size);


	deallocate(& root);
	return 0;
}




node * * node_next_to_array (node * head, int s) {
	node * * a_of_node_next = new node * [s];
	a_of_node_next[0] = head;
	for (int i = 1; i < s; i++) {
		a_of_node_next[i] = head->next;
		head = head->next;
	}
	return a_of_node_next;
}


void insert_new_at_front(node * * head, int * a, int s) {
	for (int i = 0; i < s; i++) {
		node * temp = new node; 
		temp->data = a[i];
		temp->next = * head;
		* head = temp;
	}
}


/*
void insert_new_at_front(node * * head, int * a, int length) {
	node * temp = new node;
	for (int i = 0; i < length; i++) {
		temp->data = a[i];
		temp->next = * head;
		* head = temp;
	}
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

void print_array(node * * a, int s) {
	std::cout << "array: " << std::endl;
	for (int i = 0; i < s; i++) {
		std::cout << a[i] << std::endl;
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
