#include <iostream> // cin, cout
#include <cstdlib> 
#include <string> // string

struct run_node {
	std::string name;
	float time_sec;
	run_node * next;
} ;

void print_node(run_node * existing_node);
int counter_total(run_node * existing_node);
int counter_name(run_node * existing_node, std::string end_name);
int counter_time(run_node * existing_node, float end_time);
void insert_new_at_end(run_node * * existing_node, std::string new_name, float new_time);
void insert_new_at_front(run_node * * existing_node, std::string new_name, float new_time);
int insert_new_after_name(run_node * * existing_node, std::string insert_after_this_name, std::string new_name, float new_time);

int main() {
	run_node * run_200m;
	run_node * node1 = new run_node;
	run_node * node2 = new run_node;
	run_node * node3 = new run_node;
	node1->name = "Bianca"; node1->time_sec = 25.57;
	node2->name = "Akmal"; node2->time_sec = 26.01;	
	node3->name = "Maurice"; node3->time_sec = 26.09;
	run_200m = node1;
	node1->next = node2;
	node2->next = node3;
	node3->next = NULL;
	node1 = node2 = node3 = NULL;

	//print_node(run_200m);
	//insert_new_at_end(& run_200m, "Aziz", 27.00);
	//insert_new_at_front(& run_200m, "Francois", 25.51);
	//print_node(run_200m);
	insert_new_after_name(& run_200m, "Maurice", "Gustov", 25.63);
	//insert_new_after_name(& run_200m, "Arthur", "Phuong", 26.73);
	//std::cout << "After running insert_new_after_name() " << std::endl;
	print_node(run_200m);
/*
	std::string count_name = "Maurice";
	float count_time = 26.01;
	std::cout << "Name " << count_name << " is located at node " << counter_name(run_200m, count_name) << std::endl;
	std::cout << "Time " << count_time << " is located at node " << counter_time(run_200m, count_time) << std::endl;
*/
	// deallocate run_200m?

	return 0;
}







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

int counter_name(run_node * existing_node, std::string end_name) {
	int counter = 0;
	while(existing_node->name != end_name) {
		counter += 1;
		existing_node = existing_node->next;
	}
	counter += 1;
	return counter;
}

int counter_time(run_node * existing_node, float end_time) {
	int counter = 0;
	while(existing_node->time_sec != end_time) {
		counter += 1;
		existing_node = existing_node->next;
	}
	counter += 1;
	return counter;
}

void insert_new_at_front(run_node * * existing_node, std::string new_name, float new_time) {
	run_node * conductor = new run_node;
	conductor->name = new_name;
	conductor->time_sec = new_time;
	conductor->next = * existing_node;
	
	* existing_node = conductor;
	conductor = NULL;
}
/*
void insert_after_name(run_node * * existing_node, std::string insert_after_this_name, std::string new_name, float new_time) {
	run_node * placeholder = * existing_node;
	std::cout << "placeholder->name: " << placeholder->name << std::endl;
	run_node * conductor = new run_node;
	conductor->name = new_name; conductor->time_sec = new_time;
	while (placeholder->name == insert_after_this_name) {
		std::cout << "what name is this: " << placeholder->name << std::endl;
		run_node * next_node_down_the_list = placeholder->next;
		std::cout << "next_node_down_the_list->name: " << next_node_down_the_list->name << std::endl;

//- USEFUL: learn that while loop may not be running, which would explain why nothing changes and nothing crashes. curious!!
//- AH, I need to do [placeholder = placeholder->next], and then create an inner loop or condition or something that performs some of the meaty brains...!!!

		placeholder->next = conductor;
		conductor->next = next_node_down_the_list;
		next_node_down_the_list = NULL;
	}
	* existing_node = placeholder;
	placeholder = conductor = NULL;
}
*/
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
	run_node * new_node = new run_node;
	run_node * placeholder; // more during else condition, before while loop begins

	// assign new values to temp new_node:
	new_node->name = new_name;
	new_node->time_sec = new_time;
	// wait to assign new_node->next till later

	 // returned value for func; condition is whether the new values got added to linked list: 0 = false, 1 = true:
	int did_insertion_work = 0;

	// if * existing_node is empty, return 0 (false), else set placeholder to * existing_node (placeholder will be used in next steps):
	if (* existing_node == NULL) {
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
			new_node->next = placeholder->next;
			placeholder->next = new_node;
			return did_insertion_work;
		} else {
			return did_insertion_work;
		};
			
	new_node = placeholder = NULL;
}


