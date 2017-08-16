/*
assignment: 
I.) linked-list-to-array-converter: 
	assign a heap array and assign it the memory addresses of nodes in linked list
	return array

II.) array-to-linked-list-converter:
	impose order of memory addresses in array onto existing linked list

assumptions:
I. & II.) 
	node of linked list part of struct
	int data; 
	node * next;

I.) API for linked list to array function
	node * * array_ify (node * head_pointer, int * size_buffer) { }
	
	function's return value is pointer to array of node *'s
	array size = size_buffer
	
	the idea of buffer (in size_buffer): 
		- doesn't contain useful information before function runs (it's like a blank notepaper that's ready for something to be written on it after the function runs or something)
		- this is the API for I.)

II.)
	node * list_ify (node * * node_array, int size) { }
	
	return value can be assigned to head_pointer in calling context "it is the new linked list"
*/

#include <iostream> // cin, cout
#include <cstdlib>

struct data_node {
	int data;
	data_node * next;
} ;

void print_node(data_node * head);

int main () {
	const int A_SIZE = 100; // this will change: probably to some weird buffer
	int * a = new int[A_SIZE];

	data_node * sort_node;
	data_node * node1 = new data_node;
	data_node * node2 = new data_node;
	data_node * node3 = new data_node;
	data_node * node4 = new data_node;
	node1->data = 7; 
	node2->data = 65; 
	node3->data = -2; 
	node4->data = 576;
	sort_node = node1; 
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = NULL;

	node1 = node2 = node3 = node4 = NULL;

	print_node(sort_node);

	// deallocate func goes here

	return 0;
}








void print_node(data_node * head) {
	if(head != NULL) { // makes sure existing_node holds information
		while (head->next != 0){ // goes through the linked list till the end
			std::cout << "data: " << head->data << std::endl;
			head = head->next;
		}
		// prints out the final chunk of data: 
		std::cout << "data: " << head->data << std::endl;
	}
}
