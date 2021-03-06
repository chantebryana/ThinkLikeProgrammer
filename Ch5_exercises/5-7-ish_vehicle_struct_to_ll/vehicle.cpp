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

//TLAP's code: 
// remove a single node from linked list, using the year as the metric to retreive a vehicle (since I never created an id variable, and to do that now would be a distraction from my other main goals): 
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

// TLAP deep copy: 
Vehicle_hoard::vehicle_node * Vehicle_hoard::copied_list(const vehicle_node * original) { // JE: check on pointers and type def's of various elements withint this function
	// if list is empty, return before performing deep copy:
	if (original == NULL) {
		return NULL;
	}
	// create new node / list on heap memory:
	vehicle_node * new_list = new vehicle_node;
	// copy the first node's data prior to the loop (b/c for that node we have to modify our new list's head pointer):
	new_list->vehicle_data = original->vehicle_data;
	// old_loop_ptr and new_loop_ptr: set up two pointers for tracking through the two lists: 
	// old_loop_ptr traverses the incoming list (original):
	vehicle_node * old_loop_ptr = original->next;
	// new_loop_ptr traverses the new, copied list. it always points to the last node we created (the node prior to where we'll add the next node):
	vehicle_node * new_loop_ptr = new_list;
	// traverse the linked list and make copies to the new list!
	while (old_loop_ptr != NULL) {
		new_loop_ptr->next = new vehicle_node;
		new_loop_ptr = new_loop_ptr->next;
		new_loop_ptr->vehicle_data = old_loop_ptr->vehicle_data;
		old_loop_ptr = old_loop_ptr->next;
	}
	// terminate the end of the new list by pointing next to NULL: 
	new_loop_ptr->next = NULL;
	// return the new, deep copied list:
	return new_list;
}

// operator overload function: 
Vehicle_hoard & Vehicle_hoard::operator=(const Vehicle_hoard & rhs) {
	if (this != & rhs) {
		deallocate(& _head); // JE do this if I keep * * in deallocate
		_head = copied_list(rhs._head);
	}
	return * this;
}

// copy constructor: 
Vehicle_hoard::Vehicle_hoard(const Vehicle_hoard & original) {
	_head = copied_list(original._head);
}

