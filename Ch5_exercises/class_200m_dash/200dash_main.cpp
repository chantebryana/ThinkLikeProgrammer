#include <iostream> // cin, cout
#include <cstdlib>
#include <string> // string
#include "./200dash.h"

int main() {
	Run runner1;
	runner1.set_name("Guillermo");
	runner1.set_rank(1);
	runner1.set_time(25.57);
	std::cout << runner1.output_string() << std::endl;

	Run runner2("Eun", 2, 26.01);
	std::cout << runner2.output_string() << std::endl;

	Runs runners_a;
/*
attempt to construct a linked list class at this point created the following errors in terminal: 

	ruby@rubyVM:~/Projects/ThinkLikeProgrammer/Ch5_exercises/class_200m_dash$ make
	mkdir -p bin
	g++ -c 200dash.cpp -o bin/200dash.o
	200dash.cpp: In member function ‘void Runs::delete_runner(Runs::run_node&)’:
	200dash.cpp:55:21: error: cannot convert ‘Runs::run_node’ to ‘Runs::run_node*’ in initialization
		 run_node * temp = list_ptr;
			                 ^~~~~~~~
	200dash.cpp:56:22: error: base operand of ‘->’ has non-pointer type ‘Runs::run_node’
		 list_ptr = list_ptr->next;
			                  ^~
	200dash.cpp: In destructor ‘Runs::~Runs()’:
	200dash.cpp:62:21: error: no matching function for call to ‘Runs::delete_runner(Runs::run_node*&)’
		delete_runner(_head);
			                 ^
	200dash.cpp:52:6: note: candidate: void Runs::delete_runner(Runs::run_node&)
	 void Runs::delete_runner(run_node & list_ptr) {
			  ^~~~
	200dash.cpp:52:6: note:   no known conversion for argument 1 from ‘Runs::run_node*’ to ‘Runs::run_node&’
	makefile:4: recipe for target '200dash.o' failed
	make: *** [200dash.o] Error 1
*/

	return 0;
}
