#include <iostream>
#include <cstdlib>
#include <string>
#include "./vehicle_a.h"
using std::cin;
using std::cout;



int main() {
	Vehicle car;
	Vehicle car2;
	Vehicle car3;
	Vehicle car4;
	car.set_mfgr('F');
	car.set_model('T');
	car.set_year(1999);
	cout << car.get_mfgr() << ", " << car.get_model() << ", " << car.get_year() << "\n";
	return 0;
}


