// w/ Jim: notes re insert_new_after_name() functionality:

//doesn't work if insert_after_this_name is the last name in the list;

does_it_work = 0;
while(placeholder->next != NULL) {
	if(placeholder->name == insert_after_this_name) {
		does_it_work = 1;
		break;
	} //else {
		//does_it_work = 0;
	//};
	placeholder = placeholder->next
}

if (does_it_work == 1) {
	one_node_ahead = placeholder->next;
	placeholder->next = new_node;
	new_node->next = one_node_ahead;

	return does_it_work;
} else {
	return does_it_work;
}



// w/ Jim: notes re deallocating heap memory:

void deallocate(* * existing_node) {
	next_node = * existing_node->next;
	while (* existing_node->next != NULL) {
		existing_node->name = NULL;
		existing_node->time_sec = NULL;
		existing_node->next = NULL;

		// go to a given node (while keeping track of the one ahead) and do: 
		delete * existing_node;
		// one delete for each 'new'
		// also deallocate heap memory used in helper functions 
	}
}

