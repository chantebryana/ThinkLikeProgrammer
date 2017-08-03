#include <iostream> // cin, cout
#include <cstdlib> 
#include <string> // string

struct run_node {
	std::string name;
	float time_sec;
	run_node * next;
} ;

void print_node(run_node * existing_node);
void insert_new_at_end(run_node * existing_node, std::string new_name, float new_time);
void insert_new_at_front(run_node * * existing_node, std::string new_name, float new_time);
void print_i();

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
	//insert_new_at_end(run_200m, "Aziz", 27.00);
	insert_new_at_front(& run_200m, "Francois", 25.51);
	print_node(run_200m);
	//print_i();

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

void insert_new_at_end(run_node * existing_node, std::string new_name, float new_time) {
	run_node * new_node;
	new_node->name = new_name; new_node->time_sec = new_time; new_node->next = NULL;
	while (existing_node->next == NULL) {
		existing_node = existing_node->next;
		existing_node->next = new_node;
	}
	new_node = NULL;
}

void insert_new_at_front(run_node * * existing_node, std::string new_name, float new_time) {
	run_node * conductor = new run_node;
	conductor->name = new_name;
	conductor->time_sec = new_time;
	conductor->next = * existing_node;
	
	* existing_node = conductor;
	conductor = NULL;
}

void print_i() {
	int * i;
	std::cout << i << std::endl;
}
