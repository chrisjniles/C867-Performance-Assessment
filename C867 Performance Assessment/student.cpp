#include "student.h"

// Section D1 - Create Student class
Student::Student() {
	studentId = "";
	firstName = "";
	lastName = "";
	emailAddress = "";
	studentAge = "";
	this->daysInCourse = new int[3];
}

Student::Student(
	string studentId,
	string firstName,
	string lastName,
	string emailAddress,
	string age,
	int daysInCourse[],
	Degree type){
	this->studentId = studentId;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->studentAge = age;
	this->daysInCourse = new int[3];
	for (int i = 0; i < 3; i++) this->daysInCourse[i] = daysInCourse[i];
}