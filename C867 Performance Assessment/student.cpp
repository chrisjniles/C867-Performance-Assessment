
#include <string>
#include <iostream>
#include "student.h"
using namespace std;

// Section D1 - Create Student class
Student::Student() {
	studentId = "";
	firstName = "";
	lastName = "";
	emailAddress = "";
	age = 0;
//	this->daysInCourse = new int[3];
}

Student::Student(string studentId, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], DegreeProgram type) {
	this->studentId = studentId;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
//	this->daysInCourse = new int[3];
	for (int i = 0; i < 3; i++) this->daysInCourse[i] = daysInCourse[i];
}

Student::~Student() {
//	delete[] daysInCourse;
}


//D2a - define accessors
string Student::GetStudentId() {
	return studentId;
}

string Student::GetFirstName() {
	return firstName;
}

string Student::GetLastName() {
	return lastName;
}

string Student::GetEmailAddress() {
	return emailAddress;
}

int Student::GetAge() {
	return age;
}

int* Student::GetDaysInCourse() {
	return daysInCourse;
}

DegreeProgram Student::GetDegreeProgram() {
	return degreeProgram;
}

//D2b - define mutators
void Student::SetStudentId(string studentId) {
	this->studentId = studentId;
	return;
}

void Student::SetFirstName(string firstName) {
	this->firstName = firstName;
	return;
}

void Student::SetLastName(string lastName) {
	this->lastName = lastName;
	return;
}

void Student::SetEmailAddress(string emailAddress) {
	this->emailAddress = emailAddress;
	return;
}

void Student::SetAge(int age) {
	this->age = age;
	return;
}

void Student::SetDaysCourseComplete(int daysInCourse[]) {
	for (int i = 0; i < 3; i++) this->daysInCourse[i] = daysInCourse[i];
	return;
}

// Section D2e - print specific student data
void Student::printStudent() {
	int* tempdays = GetDaysInCourse();
	cout << "Student ID: " << GetStudentId()
		<< "First Name: " << GetFirstName()
		<< "\t Last Name: " << GetLastName()
		<< "\t Student Age: " << GetAge();
	cout << "\t Days In Course: {" << tempdays[0] << ", " << tempdays[1] << ", " << tempdays[2] << "}";
	cout << "\t Degree Program: " << degreeProgramString[(int) GetDegreeProgram()] << "." << endl;
}