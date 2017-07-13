#include <string> 
class Vehicle {
	public: 
		Vehicle();
		Vehicle(std::string new_mfgr, std::string new_model, int new_year);
		std::string get_mfgr();
		void set_mfgr(std::string new_mfgr);
		std::string get_model();
		void set_model(std::string new_model);
		int get_year();
		void set_year(int new_year);
	private: 
		std::string _mfgr;
		std::string _model;
		int _year;
};
