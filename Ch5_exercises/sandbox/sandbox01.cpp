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

