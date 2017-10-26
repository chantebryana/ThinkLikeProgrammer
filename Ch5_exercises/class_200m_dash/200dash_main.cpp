#include <iostream> // cin, cout
#include <cstdlib>
#include <string> // string
#include "./200dash.h"

int main() {
	Run runner;
	runner.set_name("Guillermo");
	runner.set_rank(1);
	runner.set_time(25.57);
	std::cout << runner.output_string() << "\n";

	return 0;
}
