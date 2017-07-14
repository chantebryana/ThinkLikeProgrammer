#include <iostream>
#include <cstdlib>
using std::cin;
using std::cout;

class Vehicle {
	public: 
		Vehicle();
		Vehicle(int new_year);
		int get_year();
		void set_year(int new_year);
	private: 
		int _year;
};

Vehicle::Vehicle() {
	set_year(0);
	//_year = 0;
}

Vehicle::Vehicle(int new_year) {
	set_year(new_year);
};

void Vehicle::set_year(int new_year) {
	_year = new_year;
}

int Vehicle::get_year() {
	return _year;
}

int main() {
	Vehicle car;
	//cout << car.get_year() << "\n";
	car.set_year(1999);
	cout << car.get_year() << "\n";
	return 0;
}


