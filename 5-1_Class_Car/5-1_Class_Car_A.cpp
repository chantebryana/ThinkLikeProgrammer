#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include "./vehicle_a.h"

int main() {
	Vehicle car;
	car.set_mfgr("Ford");
	car.set_model("Taurus");
	car.set_year(1999);
	// exercise 5-2 -- supporting method:
	std::cout << car.output_string() << "\n";

	//simple datetime tutorial: https://www.tutorialspoint.com/cplusplus/cpp_date_time.htm
	time_t now = time(0);
	tm *ltm = localtime(&now);
	std::cout << "Year " << 1900 + ltm->tm_year<<std::endl;

	return 0;
}


