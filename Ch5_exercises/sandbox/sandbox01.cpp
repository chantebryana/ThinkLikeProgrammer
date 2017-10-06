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
		} ;
	public: 
		run_class();
		~run_class();
	private: 
		typedef run_node * runners;
		runners _head;
		void deallocate(runners * _head);		
} ;

//
//
//
//

// constructor: 
run_class::run_class() {
	_head = NULL;
}

// destructor helper function: 
void run_class::deallocate(runners * _head) {
	while (* _head) {
		runners temp;
		temp = * _head;
		* _head = (* _head)->next;
		delete temp;
	}
}

// destructor, using helper function deallocate():
run_class::~run_class() {
	deallocate(& _head);
}

/*
>>
>>>>
>>>>>>
>>>>
>>
*/
int main () {


	return 0;
}
