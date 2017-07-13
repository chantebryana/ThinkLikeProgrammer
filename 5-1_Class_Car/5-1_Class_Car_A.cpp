#include <iostream>
#include <cstdlib>
#include <string>
#include "./vehicle_a.h"

int main() {
	Vehicle car;
	car.set_mfgr("Ford");
	car.set_model("Taurus");
	car.set_year(1999);
	// exercise 5-2 -- supporting method:
	std::cout << car.output_string() << "\n";
	return 0;
}


