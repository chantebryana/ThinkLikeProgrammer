// dynamically find length of linked list to dynamically assign array length to heap array in linked_list_scratchpad.cpp
// adapt counter function found in linked_list_scratchpad.cpp

int counter_total(run_node * existing_node) {
	int counter = 0;
//	while (existing_node->next != NULL) {
	while(existing_node->next != NULL) {
		counter += 1;
		existing_node = existing_node->next;
	}
	counter += 1;
	return counter;
}

// adapt counter function to naming conventions / variable formats found in linked_list_sort_b.cpp
int find_length_linked_list(node * head) {
	int counter = 0;
	while (head->next != NULL) {
		counter += 1;
		head = head->next;
	}
	counter += 1;
	return counter;
}
