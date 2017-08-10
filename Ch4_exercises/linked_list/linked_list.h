#include <iostream> // cin, cout
#include <cstdlib> 
#include <string> // string

struct run_node {
	std::string name;
	float time_sec;
	run_node * next;
} ;

void print_node(run_node * existing_node) {
	if(existing_node != NULL) { // makes sure existing_node holds information
		while (existing_node->next != 0){ // goes through the linked list till the end
			std::cout << "runner: " << existing_node->name << ", time(sec): " << existing_node->time_sec << std::endl;
			existing_node = existing_node->next;
		}
		// prints out the final chunk of data: 
		std::cout << "runner: " << existing_node->name << ", time(sec): " << existing_node->time_sec << std::endl;
	}
}

void insert_new_at_front(run_node * * existing_node, std::string new_name, float new_time) {
	run_node * conductor = new run_node;
	conductor->name = new_name;
	conductor->time_sec = new_time;
	conductor->next = * existing_node;
	
	* existing_node = conductor;
	conductor = NULL;
}

void insert_new_at_end(run_node * * existing_node, std::string new_name, float new_time) {
	run_node * new_node = new run_node;
	run_node * placeholder; // more after else

	new_node->name = new_name;
	new_node->time_sec = new_time;
	new_node->next = NULL;

	if (* existing_node == NULL) {
		* existing_node = new_node;
	} else {
		placeholder = * existing_node;
		while (placeholder->next != NULL) {
			placeholder = placeholder->next;  
			std::cout << "placeholder: " << placeholder << std::endl;
		}
		placeholder->next = new_node;
		//* existing_node = placeholder;  // CE DON'T NEED THIS LINE HERE OR ANYWHERE!!!!
	}

	new_node  = placeholder = NULL;
}

int insert_new_after_name(run_node * * existing_node, std::string insert_after_this_name, std::string new_name, float new_time) {
	run_node * placeholder; // more during else condition, before while loop begins

	 // returned value for func; condition is whether the new values got added to linked list: 0 = false, 1 = true:
	int did_insertion_work = 0;

	// if * existing_node is empty, return 0 (false), else set placeholder to * existing_node (placeholder will be used in next steps):
	if (* existing_node == NULL) {
		placeholder = NULL;
		return did_insertion_work;
	} else {
		placeholder = * existing_node;
	}

		// iterate through linked list. if loop finds insert_after_this_name, set did_insertion_work to 1 (true) and break before fininshing the loop to save the place in the linked list for the next steps; else did_insertion_work is still set to 0 and placeholder is set to the last node of the list: 
		while (placeholder->next != NULL) { 
			if (placeholder->name == insert_after_this_name) {
				did_insertion_work = 1;
				break;
			};
			placeholder = placeholder->next;
		};
		// final check on last node of linked list (while loop ends before last node can get checked):
		if (placeholder->name == insert_after_this_name) {
			did_insertion_work = 1;
		};

		// if insert_after_this_name is in the linked list, then add the new_node after it and return 1 (true); else, do nothing and return 0 (false):
		if (did_insertion_work == 1) {
			// assign new values to temp new_node:
			run_node * new_node = new run_node;
			new_node->name = new_name;
			new_node->time_sec = new_time;

			// insert new_node in its proper place in * existing_node via placeholder heap pointer:
			new_node->next = placeholder->next;
			placeholder->next = new_node;

			// deallocate new_node and placeholder pointers from the heap:
			new_node = placeholder = NULL;
	
			// return 1 (true):
			return did_insertion_work;
		} else {
			// deallocate new_node and placeholder pointers from the heap:
			placeholder = NULL;

			// return 0 (false):
			return did_insertion_work;
		};
}

void deallocate(run_node * * existing_node) {
	while (* existing_node) {
		run_node * placeholder;
		placeholder = * existing_node;
		* existing_node = (* existing_node)->next;
		delete placeholder;
		// don't need to explicity delete * existing_node b/c it's already set to NULL thanks to the while loop
	}
}

