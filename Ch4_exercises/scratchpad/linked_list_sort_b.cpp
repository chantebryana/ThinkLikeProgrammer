#include <iostream> // cin, cout
#include <cstdlib> // qsort plus much more

struct node {
	int data;
	node * next;
} ;

void print_node(node * head);
void deallocate(node * * head);

int main () {
	node * root = new node;
	root->data = 7;
	root->next = NULL;

	print_node(root);

	int user_input;
	int quit = 0;
	std::cout << "enter a series of non-zero integers; enter a letter to quit: " << std::endl;
	while (!quit) {
		std::cin >> user_input;
		if (user_input != 0) {
			node * temp = new node;
			temp->data = user_input;
			temp->next = root;
			root = temp;
			temp = NULL;
		} else if (user_input == 0) {
			std::cout << "all done!" << std::endl;
			quit = 1;
		} else {
			std::cout << "input error" << std::endl;
			quit = 1;
		}
	}

	print_node(root);
/*
//	int * user_var;
	int n;
	std::cout << "How many values? ";
	std::cin >> n;
	int * user_var = new int[n];

	for (int i = 0; i < n; i++) {
		std::cout << "Enter non-zero integer for value number " << i+1 << " of " << n << ": ";
		std::cin >> user_var[i];
		if (user_var[i] == 0) {
			break;
		}
	}

	for (int i = 0; i < n; i++) {
		std::cout << user_var[i] << " ";
	}
	std::cout << std::endl;
*/
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
