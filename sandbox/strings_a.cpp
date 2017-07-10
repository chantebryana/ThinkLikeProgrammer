#include <iostream>
#include <string>
using namespace std;

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

int studentRecord::getId() {
	return _studentId;
}

void studentRecord::setGrade(int newGrade) {
	_grade = newGrade;
}

int studentRecord::getGrade() {
	return _grade;
}

void studentRecord::setId(int newId) {
	_studentId = newId;
}

string studentRecord::getName() {
	return _name;
}

void studentRecord::setName(string newName) {
	_name = newName;
}

studentRecord::studentRecord(int newId, int newGrade, string newName) {
	setId(newId);
	setGrade(newGrade);
	setName(newName);
}

studentRecord::studentRecord() {
	setId(0);
	setGrade(0);
	setName("");
}

int main () {

	studentRecord studentRecord; 
	studentRecord.setId(01);
	studentRecord.setGrade(97);
	studentRecord.setName("Bob");
	cout << studentRecord.getId() << " " << studentRecord.getGrade() << " " << studentRecord.getName() << "\n";
   return 0;
}

