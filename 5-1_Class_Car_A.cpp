#include <iostream>
#include <cstdlib>
#include <string>
using std::cin;
using std::cout;

class Vehicle {
	public: 
		Vehicle();
		Vehicle(char new_mfgr, char new_model, int new_year);
		//Vehicle(char new_mfgr);
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

Vehicle::Vehicle() {
	//_mfgr = '';
	set_mfgr(' ');
}

Vehicle::Vehicle(char new_mfgr, char new_model, int new_year) {
	set_mfgr(new_mfgr);
	set_model(new_model);
	set_year(new_year);
};

void Vehicle::set_mfgr(char new_mfgr) {
	_mfgr = new_mfgr;
}

char Vehicle::get_mfgr() {
	return _mfgr;
}

void Vehicle::set_model(char new_model) {
	_model = new_model;
}

char Vehicle::get_model() {
	return _model;
}

void Vehicle::set_year(int new_year) {
	_year = new_year;
}

int Vehicle::get_year() {
	return _year;
}

int main() {
	Vehicle car;
	car.set_mfgr('F');
	car.set_model('T');
	car.set_year(1999);
	cout << car.get_mfgr() <<", "<< car.get_model() << ", " << car.get_year() << "\n";
	return 0;
}


