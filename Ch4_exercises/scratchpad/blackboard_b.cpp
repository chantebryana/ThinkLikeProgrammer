#include <iostream> // cin, cout
#include <cstdlib> // qsort plus much more

struct node {
	int data;
	node * next;
} ;

// void insert_new_at_front(node * * head, int * a, int length);
void print_node(node * head);
void insert_new_at_front(node * * head, int * a, int s);
void deallocate(node * * head);

int main () {
	int size = 6;
	int array[size] = {1,2, 3, 4, 5, 6};
	node * root = new node;
	root->data = 0;
	root->next = NULL;

	std::cout << & root << std::endl;
	std::cout << root << std::endl;
	std::cout << root->data << std::endl;
	std::cout << root->next << std::endl;

	insert_new_at_front(& root, array, size);
	print_node(root);

	deallocate(& root);
	return 0;
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


// deallocate heap memory used up by linked list head: 
void deallocate(node * * head) {
	while (* head) {
		node * temp;
		temp = * head;
		* head = (* head)->next;
		delete temp;
	}
}
