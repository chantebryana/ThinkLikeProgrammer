// notes from second example problem in chapter 5: 
// tracking an unknown quantity of student records

// student record contains student number (int), a grade (int), and a student name (string)
// functions: addRecord (expected to be called frequently: make efficient), recordWithNumber (note that this function is new), removeRecord
// also note that none of the functions make reference to a pointer parameter (part of class encapsulation)

class studentCollection {
	private: 
	struct studentNode {
		studentRecord studentData;
		studentNode * next;
	}
	public: 
		studentCollection();
		void addRecord(studentRecord newStudent);
		studentRecord recordWithNumber(int idNum);
		void removeRecord(int idNum);
		~studentCollection();
	private: 
		typedef studentNode * studentList;
		studentList _listHead;
		void deleteList(studentList & listPtr);
} ;

// CE guessing around: do I need this? 
class studentRecord {
	public: 
		studentRecord();
		studentRecord(int newGrade, int newID, string newName);
		int grade();
		void setGrade(int newGrade);
		int studentID();
		void setStudentID(int newID);
		string name();
		void setName(string newName);
	private: 
		int _grade;
		int _studentID;
		string _name;
}

//
//
//
//
studentCollection::studentCollection() {
	_listHead = NULL;
}

void studentCollection::addRecord(studentRecord newStudent) {
	studentNode * newNode = new studentNode;
	newNode->studentData = newStudent;
	newNode->next = _listHead;
	_listHead = newNode;
}

studentRecord studentCollection::recordWithNumber(int idNum) {
	studentNode * loopPtr = _listHead;
	// Order matters because of short-circuit evaluation. NULL condition must be placed before idNum condition: if the first half of a boolean condition is met, then it won't consider the second half:
	while (loopPtr != NULL && loopPtr->studentData.studentID() != idNum) {
		loopPtr = loopPtr->next;
	}
	// if _listHead points to NULL or if the user-inputted idNum is invalid, then create an obviously dummy record and return it; else return the node within linked list that matches idNum:
	if (loopPtr == NULL) {
		studentRecord dummyRecord(-1, -1, "");
		return dummyRecord;
	} else { 
		return loopPtr->studentData;
	}
}

void studentCollection::removeRecord(int idNum) {
	studentNode * loopPtr = _listHead;
	studentNode * trailing = NULL;
	while (loopPtr != NULL && loopPtr->studentData.studentID() != idNum) {
		trailing = loopPtr;
		loopPtr = loopPtr->next;
	}
	if(loopPtr == NULL) {
		return;
	} 
	if(trailing == NULL) {
		_listHead = _listHead->next;
	} else {
		trailing->next = loopPtr->next;
	}
	delete loopPtr;
}

void studentCollection::deleteList(studentList & listPtr) {
	while (listPtr != NULL) {
		studentNode * temp = listPtr;
		listPtr = listPtr->next;
		delete temp;
	}
}

studentCollection::~studentCollection() {
	deleteList(_listHead);
}

//
//
//
//
int main () {

	return 0;
}
