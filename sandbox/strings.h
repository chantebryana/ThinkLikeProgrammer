class studentRecord {
	public: 
		studentRecord();
		studentRecord(int newId, int newGrade, string newName);
		int getId();
		void setId(int newId);
		int getGrade();
		void setGrade(int newGrade);
		string getName();
		void setName(string newName);
	private: 
		int _studentId;
		int _grade;
		string _name;
};
