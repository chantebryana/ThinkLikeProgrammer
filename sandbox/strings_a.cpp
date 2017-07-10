// from https://www.tutorialspoint.com/cplusplus/cpp_strings.htm
// exploring strings to better understand how they work 
// for use in 5-1_Class_Car_A.cpp exercise

#include <iostream>
#include <string>
using namespace std;

struct student {
	int studentID; 
	string name;
};

class studentRecord {
	public: 
		studentRecord();
		studentRecord(int newId, int newGrade, string newName);
//		studentRecord(int newId);
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

/*
studentRecord::studentRecord(int newId) {
	setId(newId);
}

studentRecord::studentRecord() {
	setId(0);
}
*/
int main () {
	const int ARRAY_SIZE = 3;
	student studentArray[ARRAY_SIZE] = {
		{01, "Wonky"}, 
		{02, "Woozie"}, 
		{03, "Wizbang"}
	};
	cout << studentArray[0].name << "\n";

	studentRecord studentRecord; 
	studentRecord.setId(01);
	studentRecord.setGrade(97);
	studentRecord.setName("Bob");
	cout << studentRecord.getId() << " " << studentRecord.getGrade() << " " << studentRecord.getName() << "\n";
/*
   string str1 = "Hello";
   string str2 = "World";
   string str3;
   int  len ;

   // copy str1 into str3
   str3 = str1;
   cout << "str3 : " << str3 << endl;

   // concatenates str1 and str2
   str3 = str1 + str2;
   cout << "str1 + str2 : " << str3 << endl;

   // total lenghth of str3 after concatenation
   len = str3.size();
   cout << "str3.size() :  " << len << endl;
*/
   return 0;
}

