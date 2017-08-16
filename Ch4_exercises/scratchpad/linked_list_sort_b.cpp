#include <iostream> // cin, cout
#include <cstdlib> // qsort plus much more

struct node {
	int data;
	node * next;
} ;

void deallocate(node * * head);
void print_node(node * head);

int main () {
	node * root = new node;
	root->data = 7;
	root->next = NULL;

	print_node(root);

	deallocate(& root);
	return 0;
}



void print_node(node * head) {
	if (head != NULL) {
		while (head->next != 0) {
			std::cout << "data: " << head->data << std::endl;
			head = head->next;
		}
		std::cout << "data: " << head->data << std::endl;
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
