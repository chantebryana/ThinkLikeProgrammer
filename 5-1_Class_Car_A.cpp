#include <iostream>
#include <cstdlib>
using std::cin;
using std::cout;

class Vehicle {
	public: 
		Vehicle();
		Vehicle(char new_mfgr, char new_model, int new_year);
		char get_mfgr();
		void set_mfgr(char new_mfgr);
		char get_model();
		void set_model(char new_model);
		int get_year();
		void set_year(int new_year);
	private: 
		char _mfgr;
		char _model;
		int _year;
};

void Vehicle::set_mfgr(char new_mfgr) {
	_mfgr = new_mfgr;
}

char Vehicle::get_mfgr() {
	// look up struct to find the mfgr I want or maybe the whole list?
	return _mfgr;
}

int main() {
	Vehicle car;
	car.set_mfgr("Ford");
	cout << car.get_mfgr() << "\n";
	return 0;
}



//[ [mfgr => "Ford", model => "Taurus", year => 1999], [mfgr => "Ford", model => "Crown Victoria", year => 2008], [mfgr => "Jeep", model => "Liberty Sport", year => 2008] ]
