#include <iostream> // cin, cout
#include <cstdlib>
#include <string> // string

class Run {
	public: 
		Run();
		Run(std::string new_name, int new_rank, float new_time);
		std::string get_name();
		void set_name(std::string new_name);
		int get_rank();
		void set_rank(int new_rank);
		float get_time();
		void set_time(float new_time);
		std::string output_string();
	private: 
		std::string _name;
		int _rank;
		float _time;
} ;

class Runs {
	private: 
		struct run_node {
			Run run_record;
			run_node * next;
		} ;
	public: 
		Runs();
		Runs(const Runs & original);
		~Runs();
		void add_front(Run new_record);
		void add_end(Run new_record);
		Run retreive_record(std::string name);
		//void print(Runs runners, std::string name);
		//void print_all();
		void size_of_list();
		Runs & operator=(const Runs & rhs);
	private: 
		run_node * _head;
		void delete_record(run_node * & list_ptr); 
		run_node * copied_list(const run_node * original);
} ;


