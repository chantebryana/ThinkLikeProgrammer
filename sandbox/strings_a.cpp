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
		studentRecord(string newName);
		int getId();
		void setId(int newId);
		string getName();
		void setName(string newName);
	private: 
		int _studentId;
		string _name;
};

int studentRecord::getId() {
	return _studentId;
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

studentRecord::studentRecord(int newId, string newName) {
	setId(newId);
	setName(newName);
}

studentRecord::studentRecord() {
	setId(0);
	setName("");
}

int main () {
	const int ARRAY_SIZE = 3;
	student studentArray[ARRAY_SIZE] = {
		{01, "Wonky"}, 
		{02, "Woozie"}, 
		{03, "Wizbang"}
	};
	cout << studentArray[0].name << "\n";

	//studentRecord studentRecord; 
	//studentRecord.setName("Bob");
	//cout << studentRecord.getName() << "\n";
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

