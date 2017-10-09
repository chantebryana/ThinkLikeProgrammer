#include <iostream>
#include <cstdlib>
#include <string>
#include "./vehicle.h"

int main() {
	// initialize car (Vehicle struct):
	Vehicle car;
	// set make, model, year variables of struct: 
	car.set_mfgr("Ford");
	car.set_model("Taurus");
	car.set_year(1999);
	// output struct's contents:
	std::cout << car.output_string() << "\n";
	// output age of vehicle (today minus vehicle year):
	std::cout << "Age of vehicle: " <<  car.age_of_vehicle() << " year(s)" << std::endl;
	return 0;
}


