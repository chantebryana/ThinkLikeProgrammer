// CE: trying to put node-address-to-array functionality into its own black box: 

int main() {
	...
	node_address_to_array(root, address_of, SOME_NUM); // CE: does (& address_of) even work? refer to history of insertion_sort.cpp to try to figure it out
// CE: I guess i don't need (& address_of) -- i could maybe just do it plain and the function would still directly manipulate the array (at least, based on notes for insertion_sort.cpp)
// CE: ah, but there may be one difference, which is that the array in insertion_sort.cpp was just a single pointer (int * p_int_array = new int[ARRAY_SIZE];) whereas the array in linked_list_sort_b.cpp is a double pointer (int * * address_of = new int * [SOME_NUM];) --> that would seem to have an impact on the function definition side, not on the function calling side, though (that's the difference)
	...
}

void node_address_to_array (node * head, int * * array, const int a_length) {
	node * temp = head;
	for (int i = 0; i < a_length; i++) {
		* array[i] = &temp->data;
		// if linked list ends before array loop, break out: 
		if (temp->next == NULL) {break;}
		temp = temp->next; // or (*temp).next
	}
	temp = NULL;
}

