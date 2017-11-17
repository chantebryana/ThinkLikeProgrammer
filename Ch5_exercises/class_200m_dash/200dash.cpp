#include "./200dash.h"

Run::Run() {
	set_name("");
}

Run::Run(std::string new_name, int new_rank, float new_time) {
	set_name(new_name);
	set_rank(new_rank);
	set_time(new_time);
}

void Run::set_name(std::string new_name) {
	_name = new_name;
}

std::string Run::get_name() {
	return _name;
}

int Run::get_rank() {
	return _rank;
}

void Run::set_rank(int new_rank) {
	_rank = new_rank;
}

float Run::get_time() {
	return _time;
}

void Run::set_time(float new_time) {
	_time = new_time;
}

std::string Run::output_string() {
	std::string output_var = "";
	output_var = "\"" + std::to_string(_rank) + " " + _name + " " + std::to_string(_time) + "\"";
	return output_var;
}


//
//
//
//
Runs::Runs() {
	_head = NULL;
}

Runs::run_node * Runs::copied_list(const run_node * original) {
	if (original == NULL) {
		return NULL;
	}
	run_node * new_list = new run_node;
	new_list->run_record = original->run_record;
	run_node * old_loop_ptr = original->next;
	run_node * new_loop_ptr = new_list;
	while (old_loop_ptr != NULL) {
		new_loop_ptr->next = new run_node;
		new_loop_ptr = new_loop_ptr->next;
		new_loop_ptr->run_record = old_loop_ptr->run_record;
		old_loop_ptr = old_loop_ptr->next;
	}
	new_loop_ptr->next = NULL;
	return new_list;
}

Runs::Runs(const Runs & original) {
	_head = copied_list(original._head);
}

void Runs::delete_record(run_node * & list_ptr) { 
	while (_head != NULL) {
		run_node * temp = list_ptr;
		list_ptr = list_ptr->next;
		delete temp;
	}
}

Runs::~Runs() {
	delete_record(_head);
}

void Runs::add_front(Run new_record) {
	run_node * temp = new run_node;
	temp->run_record = new_record;
	temp->next = _head;
	_head = temp;
}

void Runs::add_end(Run new_record) {
	run_node * new_node = new run_node;
	new_node->run_record = new_record;
	new_node->next = NULL;

	if (_head == NULL) {
		_head = new_node;
	} else {
		//run_node * placeholder = new_node; // CE: no no no!! all wrong!
		run_node * placeholder = _head;
		while (placeholder->next != NULL) {
			placeholder = placeholder->next;
		}
		placeholder->next = new_node;
	}
}

Run Runs::retreive_record(std::string name) {
	run_node * temp = _head;
	while (temp != NULL && temp->run_record.get_name() != name) {
		temp = temp->next;
	}
	if (temp == NULL) {
		Run dummy_runner("", -1, -1.0);
		return dummy_runner;
	} else {
		return temp->run_record;
	}
}
/*
void Runs::print(Runs runners, std::string name) {
	std::cout << runners.retreive_record(name).output_string() << std::endl;
}
*/
/*
void Runs::print_all() {
	run_node * temp = _head;
	while (temp->next != NULL) {
		std::cout << temp->_rank << ". " << temp->_name << ": " << temp->_time << " sec" << std::endl;
		temp = temp->next;
	}
}
*/

void Runs::size_of_list() {
	run_node * temp = _head;
	int counter = 0;
	while (temp != NULL) {
		counter ++;
		temp = temp->next;
	}
	counter ++;
	std::cout << "size of list: " << counter << "." << std::endl;
}
Runs & Runs::operator=(const Runs & rhs) {
	if (this != & rhs) {
		delete_record(_head);
		_head = copied_list(rhs._head);
	}
	return * this;
}
