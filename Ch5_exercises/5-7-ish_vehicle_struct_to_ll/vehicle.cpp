//#include <string>
//#include <iostream>
//#include <cstdlib>
#include <ctime>
#include "./vehicle.h"



//
//
//
//
// helper functions for Vehicle class: 
// constructor: 
Vehicle::Vehicle() {
	set_mfgr("");
}

// constructor (vehicle make, model, year to struct): 
Vehicle::Vehicle(std::string new_mfgr, std::string new_model, int new_year) {
	set_mfgr(new_mfgr);
	set_model(new_model);
	set_year(new_year);
};

// set_mfgr:
void Vehicle::set_mfgr(std::string new_mfgr) {
	_mfgr = new_mfgr;
}

// get_mfgr:
std::string Vehicle::get_mfgr() {
	return _mfgr;
}

// set_model:
void Vehicle::set_model(std::string new_model) {
	_model = new_model;
}

// get_model: 
std::string Vehicle::get_model() {
	return _model;
}

// set_year: 
void Vehicle::set_year(int new_year) {
	_year = new_year;
}
// get_year: 
int Vehicle::get_year() {
	return _year;
}

// output struct's contents:
std::string Vehicle::output_string() {
	std::string output_var = "";
	output_var = "\"" + std::to_string(_year) + " " + _mfgr + " " + _model + "\"";
	return output_var;
}

// output age of vehicle (today minus vehicle year):
int Vehicle::current_year() {
	time_t now = time(0);
	tm *ltm = localtime(&now);
	int year = 1900 + ltm->tm_year;
	return year;
}

// private supporting method for age_of_vehicle:
int Vehicle::age_of_vehicle() {
	//int age_of_vehicle = current_year() - _year;
	//return age_of_vehicle;
	return current_year() - _year;
}

//
//
//
//
// helper functions for Vehicle_hoard class:

// constructor: 
Vehicle_hoard::Vehicle_hoard() {
	_head = NULL;
}

// destructor helper function:
// adapted from Ch4_exercises/linked_list/linked_list.h:
void Vehicle_hoard::deallocate(vehicle_node * * _head) {
	while (* _head) {
		vehicle_node * temp;
		temp = * _head;
		* _head = (* _head)->next;
		delete temp;
	}
}

// destructor: 
Vehicle_hoard::~Vehicle_hoard() {
	deallocate(& _head);
}

// add new node to linked list:
void Vehicle_hoard::add_record(Vehicle new_vehicle){
	vehicle_node * temp = new vehicle_node;
	temp->vehicle_data = new_vehicle;
	temp->next = _head;
	_head = temp;
}
/*
// prints contents of linked list:
void Vehicle_hoard::print(Vehicle list_node) {
	if(list_node != NULL) {
		while(list_node->next !=0) {
			std::cout << list_node->vehicle_data << std::endl;
			list_node = list_node->next;
		}
		std::cout << list_node->vehicle_data << std::endl;
	}
}
*/

// returns LL record based on year:
// (need something like the following in main() to actually output node data)
// std::cout << lotsa_cars.retreive_record(1999).output_string() << "\n";
Vehicle Vehicle_hoard::retreive_record(int yr) {
	vehicle_node * temp = _head;
	// create smarter while conditions to account for NULL pointer (ie, if list is empty or user's argument doesn't match list values)
	// (note that order matters: 'temp != NULL' must go before 'temp->vehcile_data.get_year() != yr' b/c of C++'s short-circuit evaluation)
	while (temp != NULL && temp->vehicle_data.get_year() != yr) {
		temp = temp->next;
	}
	// smarter return condition: if temp points to NULL, return dummy record, else return the appropriate vehicle node (the value pointed to based on while loop logic): 
	if (temp == NULL ) {
		Vehicle dummy_vehicle("", "", -1);
		return dummy_vehicle;
	} else {
		return temp->vehicle_data;
	}
}

/*
//CE's attempt: 
// remove a single node from linked list, using the year as the metric to retreive a vehicle (since I never created an id variable, and to do that now would be a distraction from my other main goals): 
void Vehicle_hoard::remove_record(int yr) {
	vehicle_node * temp = _head;
	if (temp->vehicle_data.get_year() == yr) {
		// connects the pointer in _head to the node past the deleted one:
		_head->next = temp->next;
		//temp = NULL; // CE: do I need to do this? does this avoid memory leak?
		delete temp; // CE: I think this is what's needed to avoid memory leak; also same memory depth as is shows in deallocate() --> hopefully it works.
	} else {
		temp = temp->next;
		vehicle_node * previous = _head;
		while (temp->vehicle_data.get_year() != yr) {
			temp = temp->next;
			previous = previous->next;
		}
		// remove node
		// connect previous node to next node
	}
}
*/

//TLAP's code: 
void Vehicle_hoard::remove_record(int yr) {
	vehicle_node * temp = _head;
	vehicle_node * previous = NULL;
	while (temp != NULL && temp->vehicle_data.get_year() != yr) {
		previous = temp;
		temp = temp->next;
	}
	// if temp is NULL (if list is empty or int yr doesn't match any year nodes), return without deleting any nodes: 
	if (temp == NULL) {
		return;
	}
	// if deleting first node (special case since nothing for previous to point to): 
	if (previous == NULL) {
		_head = _head->next;
	} else { // (if deleting any middle or end nodes)
		previous->next = temp->next;
	}
	// after performing any special steps related to the location of the node to be deleted, finally delete the dang thing from heap memory!
	delete temp;
}


