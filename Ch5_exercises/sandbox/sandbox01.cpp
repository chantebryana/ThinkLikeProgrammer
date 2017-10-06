// playing around with converting 200m dash into class

#include <iostream> // cin, cout
#include <cstdlib> 
#include <string> // string

class run_class {
	private: 
		struct run_node {
			std::string name;
			int rank;
			run_node * next;
		}
	public: 
		run_class();
		~run_class();
		void insert_new_at_front(runners new_runner);
		void print_node_rank(runners existing_node);
	private: 
		typedef run_node * runners;
		runners _head;
		int find_list_length(runners _head);
		runners * array_ify(runners _head, int * size_buff);
		runners list_ify(runners * a_nn, int s);
		int compare_node_rank(const void * void_a, const void * void_b);
		void deallocate(runners * existing_node);		
} ;

//
//
//
//

run_class::run_class() {
	_head = NULL;
}

void run_class::add_runner(runner new_runner){
	runner * 
}

// prints linked list: runner and rank nodes: 
void run_class::print_node_rank(runners existing_node) {
	if(existing_node != NULL) { // makes sure existing_node holds information
		while (existing_node->next != 0){ // goes through the linked list till the end
			std::cout << "runner: " << existing_node->name << ", rank: " << existing_node->rank << std::endl;
			existing_node = existing_node->next;
		}
		// prints out the final chunk of data: 
		std::cout << "runner: " << existing_node->name << ", rank: " << existing_node->rank << std::endl;
	}
}

// finds the length of linked list, to be used in array_ify (iterates through each node of linked list, increasing the counter one by one until reaching the end of the list): 
int run_class::find_list_length(runners _head) {
	int counter = 0;
	while (_head->next != NULL) {
		counter += 1;
		_head = _head->next;
	}
	counter += 1;
	return counter;
}
