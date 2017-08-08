#include <iostream> // cin, cout
#include <cstdlib> 
#include <string> // string
#include "./linked_list.h"

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

	run_node * null_node = NULL;

	print_node(run_200m);
	std::cout << std::endl;
	//insert_new_at_end(& run_200m, "Aziz", 27.00);
	//insert_new_at_front(& run_200m, "Francois", 25.51);
	//insert_new_after_name(& run_200m, "Maurice", "Gustov", 25.63);
	//insert_new_after_name( & null_node, "Bill", "Susan", 26.9);
	//insert_new_after_name(& run_200m, "Arthur", "Phuong", 26.73);
	print_node(run_200m);

	// deallocate run_200m:
	deallocate(& run_200m);


	return 0;
}
