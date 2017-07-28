class String {
	public: 
		String(); // constructor
		char * get_string();
		void set_string(char * new_char_array);
		char characterAt(int position);
		void append(char c);
		void concatenate(char * char_array_b);
		~String(); // destructor
	private: 
		char * char_array;
		int allocation_length(char * new_char_array);
};
