#include <iostream> // cin, cout
#include <cstdlib> 
#include <string> // string

struct run_node {
	std::string name;
	int ranking;
	float outcome_seconds;
	run_node * next;
} ;


int main() {
	run_node * run_200m;
	run_node * node1 = new run_node;
	run_node * node2 = new run_node;
	run_node * node3 = new run_node;
	node1->name = "Bianca"; node1->ranking = 1; node1->outcome_seconds = 25.57;
	node2->name = "Akmal"; node2->ranking = 2; node2->outcome_seconds = 26.01;	
	node3->name = "Maurice"; node3->ranking = 3; node3->outcome_seconds = 26.09;
	run_200m = node1;
	node1->next = node2;
	node2->next = node3;
	node3->next = NULL;
	node1 = node2 = node3 = NULL;
/*
	std::cout << run_200m->name << std::endl;
	std::cout << run_200m->ranking << std::endl;
	std::cout << run_200m->outcome_seconds << std::endl;
*/
	run_node * placeholder = run_200m;
	while(placeholder != NULL) {
	//while(run_200m != NULL) {
		//std::cout << "runner: " << run_200m->name << ", ranking: " << run_200m->ranking << ", time (sec): " << run_200m->outcome_seconds << std::endl;
		std::cout << "runner: " << placeholder->name << ", ranking: " << placeholder->ranking << ", time (sec): " << placeholder->outcome_seconds << std::endl;
		placeholder = placeholder->next;
		//run_200m = run_200m->next;
	}

	// deallocate run_200m and placeholder?

	return 0;
}
