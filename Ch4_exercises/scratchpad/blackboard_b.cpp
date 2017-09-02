#include <iostream> // cin, cout
#include <cstdlib> // qsort plus much more

struct node {
	int data;
	node * next;
} ;

void insert_new_at_front(node * * head, int * a, int length);
void print_node(node * head);
void deallocate(node * * head);

int main () {
	int size = 5;
	int array[size] = {1,2,3,4,5};
	node * root = new node;
	root->next = NULL;

	insert_new_at_front(& root, array, size);
	print_node(root);

	deallocate(& root);
	return 0;
}



void insert_new_at_front(node * * head, int * a, int length) {
	node * temp = new node;
	for (int i = 0; i < length; i++) {
		temp->data = a[i];
		temp->next = * head;
		* head = temp;
	}
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


// deallocate heap memory used up by linked list head: 
void deallocate(node * * head) {
	while (* head) {
		node * temp;
		temp = * head;
		* head = (* head)->next;
		delete temp;
	}
}
