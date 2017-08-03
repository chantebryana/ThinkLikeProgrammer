#include <iostream> // cin, cout
#include <cstdlib> 
#include <string> // string

struct run_node {
	std::string name;
	float outcome_seconds;
	run_node * next;
} ;

void print_node(run_node * placeholder);

int main() {
	run_node * run_200m;
	run_node * node1 = new run_node;
	run_node * node2 = new run_node;
	run_node * node3 = new run_node;
	node1->name = "Bianca"; node1->outcome_seconds = 25.57;
	node2->name = "Akmal"; node2->outcome_seconds = 26.01;	
	node3->name = "Maurice"; node3->outcome_seconds = 26.09;
	run_200m = node1;
	node1->next = node2;
	node2->next = node3;
	node3->next = NULL;
	node1 = node2 = node3 = NULL;

	print_node(run_200m);

	// deallocate run_200m?

	return 0;
}

void print_node(run_node * placeholder) {
	if(placeholder != NULL) { // makes sure placeholder holds information
		while (placeholder->next != 0){ // goes through the linked list till the end
			std::cout << "runner: " << placeholder->name << ", time (sec): " << placeholder->outcome_seconds << std::endl;
			placeholder = placeholder->next;
		}
		// prints out the final chunk of data: 
		std::cout << "runner: " << placeholder->name << ", time (sec): " << placeholder->outcome_seconds << std::endl;
	}
}
