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

	return 0;
}
