#include <iostream>
#include <cstdlib>
#include <string>
#include "./vehicle_a.h"
using std::cin;
using std::cout;

int main() {
	Vehicle car;
	//car.set_mfgr('F');
	car.set_mfgr("Ford");
	car.set_model('T');
	car.set_year(0);
	cout << car.get_mfgr() << ", " << car.get_model() << ", " << car.get_year() << "\n";
	return 0;
}


