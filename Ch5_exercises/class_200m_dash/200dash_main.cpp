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

	//Run runner2;
	//runner2("Eun", 2, 26.01);
/*
	two-line assignment creates this error in terminal: 
		ruby@rubyVM:~/Projects/ThinkLikeProgrammer/Ch5_exercises/class_200m_dash$ make
		mkdir -p bin
		g++ -c 200dash.cpp -o bin/200dash.o
		g++ bin/200dash.o 200dash_main.cpp -o bin/200dash_main
		200dash_main.cpp: In function ‘int main()’:
		200dash_main.cpp:14:25: error: no match for call to ‘(Run) (const char [4], int, double)’
			runner2("Eun", 2, 26.01);
				                     ^
		makefile:8: recipe for target '200dash_main' failed
		make: *** [200dash_main] Error 1
*/
	Run runner2("Eun", 2, 26.01);
	// one-line initialization works: here's the output: "2 Eun 26.010000"

	std::cout << runner2.output_string() << std::endl;

	return 0;
}
