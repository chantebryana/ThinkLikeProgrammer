#include <string> 

// manipulate single struct of vehicle data:
class Vehicle {
	public: 
		// constructor: 
		Vehicle();
		// constructor (make, model, year to struct):
		Vehicle(std::string new_mfgr, std::string new_model, int new_year);
		// get_mfgr: 
		std::string get_mfgr();
		// set_mfgr: 
		void set_mfgr(std::string new_mfgr);
		// get_model: 
		std::string get_model();
		// set_model:
		void set_model(std::string new_model);
		// get_year:
		int get_year();
		// set_year:
		void set_year(int new_year);
		// output struct's contents:
		std::string output_string();
		// output age of vehicle (today minus vehicle year):
		int age_of_vehicle();
	private: 
		// private variables of struct: 
		std::string _mfgr;
		std::string _model;
		int _year;
		// private supporting method for age_of_vehicle:
		int current_year();
};

// manipulate linked list of vehicle data:
// based on pgs 119 & 126 of TLAP ch 5:
class Vehicle_hoard {
	private: 
		struct vehicle_node {
			Vehicle vehicle_data;
			vehicle_node * next;
		} ;
	public: 
		Vehicle_hoard();
		~Vehicle_hoard();
		void add_record(Vehicle new_vehicle);
		//void print(Vehicle list_node);
		Vehicle retreive_record(int yr);
		void remove_record(int yr);
		// operator overload:
		Vehicle_hoard & operator = (const Vehicle_hoard & rhs);
		// copy constructor:
		Vehicle_hoard(const Vehicle_hoard & original);
		//Vehicle_hoard(const Vehicle_hoard * * original);
	private: 
		// (I'm not doing typedef: dumb and confusing to me)
		vehicle_node * _head;
		void deallocate(vehicle_node * * _head); // JE: I could just have vehicle_node * _head
		//void deallocate(vehicle_node * & list_ptr);
		// private method for deep copy constructor:
		vehicle_node * copied_list(const vehicle_node * original);
} ;

