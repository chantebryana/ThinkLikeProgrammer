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

	Vehicle_hoard extra_cars;
	extra_cars = copied_list(lotsa_cars);

/*
tried compiling and got all sorts of errors. See terminal printout below: 

ruby@rubyVM:~/Projects/ThinkLikeProgrammer/Ch5_exercises/5-7-ish_vehicle_struct_to_ll$ make
mkdir -p bin
g++ -c vehicle.cpp -o bin/vehicle.o
vehicle.cpp: In member function ‘Vehicle_hoard::vehicle_node Vehicle_hoard::copied_list(Vehicle_hoard::vehicle_node)’:
vehicle.cpp:169:15: error: no match for ‘operator==’ (operand types are ‘const Vehicle_hoard::vehicle_node’ and ‘long int’)
  if (original == NULL) {
               ^
In file included from /usr/include/_G_config.h:15:0,
                 from /usr/include/libio.h:31,
                 from /usr/include/stdio.h:74,
                 from /usr/include/c++/6/cstdio:42,
                 from /usr/include/c++/6/ext/string_conversions.h:43,
                 from /usr/include/c++/6/bits/basic_string.h:5417,
                 from /usr/include/c++/6/string:52,
                 from ./vehicle.h:1,
                 from vehicle.cpp:5:
vehicle.cpp:170:10: error: could not convert ‘0l’ from ‘long int’ to ‘Vehicle_hoard::vehicle_node’
   return NULL;
          ^
vehicle.cpp:175:35: error: base operand of ‘->’ has non-pointer type ‘const Vehicle_hoard::vehicle_node’
  new_list->vehicle_data = original->vehicle_data;
                                   ^~
vehicle.cpp:178:40: error: base operand of ‘->’ has non-pointer type ‘const Vehicle_hoard::vehicle_node’
  vehicle_node * old_loop_ptr = original->next;
                                        ^~
vehicle.cpp:191:9: error: could not convert ‘new_list’ from ‘Vehicle_hoard::vehicle_node*’ to ‘Vehicle_hoard::vehicle_node’
  return new_list;
         ^~~~~~~~
Makefile:4: recipe for target 'vehicle.o' failed
make: *** [vehicle.o] Error 1

*/
	// print extra_cars after performing a deep copy: 
	std::cout << lotsa_cars.retreive_record(1999).output_string() << "\n";
	std::cout << lotsa_cars.retreive_record(2002).output_string() << "\n";
	std::cout << lotsa_cars.retreive_record(2008).output_string() << "\n";

	return 0;
}


