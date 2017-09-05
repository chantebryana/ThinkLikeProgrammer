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
node * array_to_node (node * * a_nn, int s);
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
	node * root_from_array = array_to_node (array_of_node_next, size);
	print_node(root_from_array);

	deallocate(& root);
	return 0;
}



// practice assigning values of node->next instead of node or node->data into elements of heap array: this should hopefully make array-to-linked-list assignment slightly easier:
node * * node_next_to_array (node * head, int s) {
	// jank fix: add 2 to size b/c there are 2 more memory addresses of node than there are elements of array; should actually determine size by measuring size of node (not array):
	node * * a_of_node_next = new node * [s+2]; 
	// manually assign memory address of head pointer to first element of array:
	a_of_node_next[0] = head; 
	// iterate forward through node to assign values of next pointers to new heap array:
	for (int i = 1; i < s+2; i++) {
		a_of_node_next[i] = head->next; 
		head = head->next;
	}
	// return heap array:
	return a_of_node_next;
}

node * array_to_node (node * * a_nn, int s) {
	node * next_a = new node;
	next_a = a_nn[0];
	std::cout << next_a << std::endl;
	for (int i = 1; i < s+2; i++) {
		next_a->next = a_nn[i];
		std::cout << next_a->next << std::endl;
		next_a = next_a->next;
	}
	return next_a;
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
	for (int i = 0; i < s + 2; i++) { // because the 's' size in node_next_to_array is manually iterated by 2, I have to do the same here
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
