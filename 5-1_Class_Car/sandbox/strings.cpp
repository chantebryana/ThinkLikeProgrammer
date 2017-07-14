#include "./strings.h"

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

