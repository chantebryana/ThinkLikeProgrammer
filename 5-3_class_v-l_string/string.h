class String {
	public: 
		String(); // constructor
		char * get_string();
		void set_string(char * new_char_array);
		char characterAt(int position);
		~String(); // destructor
	private: 
		char * char_array;
		int length(char * new_char_array);
};
