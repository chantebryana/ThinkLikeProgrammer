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
	runners_a.add_record(runner1);
	runners_a.add_record(runner2);
	std::cout << runners_a.retreive_record("Guillermo").output_string() << std::endl;
	std::cout << runners_a.retreive_record("Eun").output_string() << std::endl;
	std::cout << runners_a.retreive_record("Mehtab").output_string() << std::endl;
/*
ruby@rubyVM:~/Projects/ThinkLikeProgrammer/Ch5_exercises/class_200m_dash$ ./bin/200dash_main 
"1 Guillermo 25.570000"
"2 Eun 26.010000"
"1 Guillermo 25.570000"
"2 Eun 26.010000"
"-1  -1.000000"

*/
	return 0;
}
