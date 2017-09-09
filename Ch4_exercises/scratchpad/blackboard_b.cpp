#include <iostream> // cin, cout
#include <cstdlib> 
#include <string> // string
#include "../linked_list/linked_list.h"

void user_selection(run_node * head) {
	std::cout << std::endl << "A runner can challenge the runner just ahead of them to try to advance up." << std::endl << "User, type in the name of a runner to challenge: " << std::endl;
	std::string user_selection;
	std::cin >> user_selection;
	std::string opponent = "";
	// iterate through linked list, keeping track of current node and 1-previous node: 
	if (head != NULL) {
		run_node * next_one = new run_node;
		next_one = head->next;
		while (head->next != 0) {
			if (next_one->name == user_selection) {
				opponent = head->name;
			}
			next_one = next_one->next;
			head = head->next;
		}
	}
	std::cout << user_selection << " challenges " << opponent << std::endl;
}


int main () {
	run_node * run_200m;
	run_node * node1 = new run_node;
	run_node * node2 = new run_node;
	run_node * node3 = new run_node;
	node1->name = "Bianca"; node1->rank = 1;
	node2->name = "Akmal"; node2->rank = 3;	
	node3->name = "Maurice"; node3->rank = 2;
	run_200m = node1;
	node1->next = node2;
	node2->next = node3;
	node3->next = NULL;

	node1 = node2 = node3 = NULL;

	// section below sorts the linked list based on time_sec: takes linked list, finds length of linked list and saving to size_buff and saves memory address pointers into an array (array_ify), sorts the array (based on time_sec node) using qsort, uses list_ify to translate the sorted array back to the linked list, then prints the results to the screen: 
	int size_buff;
	run_node * * array_of_node_address = array_ify(run_200m, & size_buff);
	//qsort(array_of_node_address, size_buff, sizeof(run_node *), compare_node);
	qsort(array_of_node_address, size_buff, sizeof(run_node *), compare_node_rank);
	run_200m = list_ify(array_of_node_address, size_buff);
	std::cout << "__200 METER DASH__" << std::endl << "  Player Roster:" << std::endl;
	print_node_rank(run_200m);
	// std::cout << std::endl << "A runner can challenge the runner just ahead of them to try to advance up." << std::endl << "User, type in the name of a runner to challenge: " << std::endl;
	// std::string user_selection;
	// std::cin >> user_selection;
	// std::cout << "User selected __" << user_selection << "__" << std::endl;
	user_selection(run_200m);


	// deallocate run_200m:
	deallocate(& run_200m);
	return 0;
}
