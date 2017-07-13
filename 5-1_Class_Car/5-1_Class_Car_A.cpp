#include <iostream>
#include <cstdlib>
#include <string>
#include "./vehicle_a.h"

int main() {
	Vehicle car;
	car.set_mfgr("Ford");
	car.set_model("Taurus");
	car.set_year(1999);
	std::cout << car.output_string() << "\n";
	//cout << car.output_string();
	//std::cout << car.get_mfgr() << ", " << car.get_model() << ", " << car.get_year() << "\n";
	return 0;
}


