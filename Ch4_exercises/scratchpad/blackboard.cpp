//JE
all uses of address_of []
node_address_to_array()
switch from int ** to node **
(an array of node *)

// ===	===	===


int main() {
...
	//int * size_buff = new int;
	int size_buff;

	node * * array_of_node_address = array_ify(root, & size_buff);
	// CE I think the above line should be written: 
	// node * * array_of_node_address[] = array_ify(root, & size_buff);
...
}

node * * array_ify(node * head, int * size_buff) {
	// create a temp to head // JE: head is a stack (within this function's memory stack allottment) of node --> I don't need to make yet another temp layer (this is in general, not just for this particular function)
	// define size_buff -- maybe using something like find_list_length() ?
	* size_buff = find_list_length(head); //JE: head will get copied AGAIN within find_list_length() function ;; JE: b/c size_buff is an int * and find_list_length() returns just a plain int, I need to add the '*' in front of size_buff variable to make sure that all the memory layers are pointing to the same place
	// declare array, point to heap, make of size size_buff
	node * * a_of_node_address = new node * [* size_buff];
	// complete for() loop of node_address_to_array() -- consider making it its own black box that I declare??
	// node_address_to_array(head, a_address_of_node, size_buff); // CE: I'd need to clean up this function to make it play nice with array_ify()
	for (int i = 0; i < * size_buff; i++) {
		a_of_node_address[i] = head;
		head = head->next;
	}
	// return array
	return a_of_node_address;
}

//...	...	...
// array_ify without educational commentary: 

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
