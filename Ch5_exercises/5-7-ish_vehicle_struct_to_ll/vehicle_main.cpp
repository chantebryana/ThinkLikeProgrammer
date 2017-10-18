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

	Vehicle car2;
	car2.set_mfgr("Jeep");
	car2.set_model("Liberty Sport");
	car2.set_year(2002);
	// output struct's contents:
	std::cout << car2.output_string() << "\n";
	// output age of vehicle (today minus vehicle year):
	std::cout << "Age of vehicle: " <<  car2.age_of_vehicle() << " year(s)" << std::endl;

	// simpler way to assign new Vehicle nodes (re p 130 of TLAP):
	Vehicle car3("Ford", "Crown Victoria", 2008);

	Vehicle_hoard lotsa_cars;
	lotsa_cars.add_record(car);
	lotsa_cars.add_record(car2);
	lotsa_cars.add_record(car3);
	//print(lotsa_cars);
	std::cout << lotsa_cars.retreive_record(1999).output_string() << "\n";
	std::cout << lotsa_cars.retreive_record(1985).output_string() << "\n";
	std::cout << lotsa_cars.retreive_record(2008).output_string() << "\n";


	// remove a single node from the linked list (p 130 TLAP): 
	lotsa_cars.remove_record(2002);
	// print lotsa_cars after removing a record: 
	std::cout << lotsa_cars.retreive_record(1999).output_string() << "\n";
	std::cout << lotsa_cars.retreive_record(2002).output_string() << "\n";
	std::cout << lotsa_cars.retreive_record(2008).output_string() << "\n";


	return 0;
}


