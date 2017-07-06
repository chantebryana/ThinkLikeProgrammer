#include "./vehicle_a.h"

Vehicle::Vehicle() {
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

