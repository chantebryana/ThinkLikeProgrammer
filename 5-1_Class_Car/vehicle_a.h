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
