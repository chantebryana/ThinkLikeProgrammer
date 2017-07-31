// notes from ch 5 classes w/ dynamic data (and pointers!)
// pp 125 - xxx TLAP

class studentRecord {
public: 
	studentRecord();
	studentRecord(int newGrade, int newID, string newName);
	int grade();
	void setGrade(int newGrade);
//...
//...

private: 
	int _grade;
	int _studentID;
	string _name;
};
// ===	===	===
class studentCollection {
private: 
	struct studentNode {
		studentRecord studentData;
		studentNode * next;
	};
public: 
	studentCollection();
	void addRecord (studentRecord newStudent);
	studentRecord recordWithNumber (int idNum);
	void removeRecord (int idNum);
	~studentCollection(); // destructor
	studentCollection & operator=(const studentCollection & rightHandSide); // operator overload
private: 
	typedef studentNode * studentList;
	studentList _listHead;
	void deleteList(studentList & listPtr); // destructor helper
	studentList copiedList(const studentList original); // deep copy
};

studentCollection::studentCollection() {
	_listHead = NULL;
};

void studentCollection::addRecord(studentRecord newStudent) {
	studentNode * newNode = new studentNode;
	newNode->studentData = newStudent;
	newNode->next = _listHead;
	_listHead = newNode;
}

// could also be labeled 'retrieveRecord' instead of 'recordWithNumber':
studentRecord studentCollection::recordWithNumber(int idNum) {
	studentNode * loopPtr = _listHead;
	while (loopPtr != NULL && loopPtr->studentData.studentID() != idNum) {
		loopPtr = loopPtr->next;
	}
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
	while (loopPtr !=NULL && loopPtr->studentData.studentID() != idNum) {
		trailing = loopPtr;
		loopPtr = loopPtr->next;
	}
	if (loopPtr == NULL) return; // could also have if/else statement like in previous func
	if (trailing == NULL) {
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

studentCollection::studentList studentCollection::copiedList(const studentList original) {
	if (original == NULL) {
		return NULL;
	}
	studentList newList = new studentNode;
	newList->studentData = original->studentData;
	studentNode * oldLoopPtr = original->next;
	studentNode * newLoopPtr = newList;
	while (oldLoopPtr != NULL) {
		newLoopPtr->next = new studentNode;
		newLoopPtr = newLoopPtr->next;
		newLoopPtr->studentData = oldLoopPtr->studentData;
		oldLoopPtr = oldLoopPtr->next;
	}
	newLoopPtr->next = NULL;
	return newList;
}

studentCollection & studentCollection::operator=(const studentCollection & rightHandSide) {
	if (this != & rightHandSide) {
		deleteList(_listHead);
		_listHead = copiedList(rightHandSide._listHead);
	}
	return * this;
}


// ...	...	...
// attempting deep copy and operator overloading

char * copied_array(const char * original);
String & operator=(const String & rhs);


char * String::copied_array(const char * original) {
	if (original == NULL) {
		return NULL;
	}
	int char_length = allocation_length(char_array);
	char * copy_char_array = new char[char_length];
	for (int i = 0; i < char_length-1; i++) {
		copy_char_array[i] = original[i];
	}
	return copy_char_array;
}

String * String::operator=(const String & rhs) {
	if (this != & rhs) {
		delete[] char_array;
		char_array = copied_array(rhs); // do i need to iterate here? i iterate in copied_array()
	}
	return * this;
}


