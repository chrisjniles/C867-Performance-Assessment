
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include "roster.h"
using namespace std;

// Section E1 - Create Roster class
Roster::Roster() {
	const string studentData[] = {
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Christopher,Niles,cniles7@wgu.edu,38,30,35,40,SOFTWARE" // Section A - Modify the “studentData Table” to include your personal information as the last item
	};

	classRosterArray = new Student[5];

	for (int i = 0; i < numStudents; i++) 
	{
		size_t rhs = studentData[i].find(",");
		string studentID = studentData[i].substr(0, rhs);

		size_t lhs = rhs + 1;
		rhs = studentData[i].find(",", lhs);
		string firstName = studentData[i].substr(lhs, rhs - lhs);

		lhs = rhs + 1;
		rhs = studentData[i].find(",", lhs);
		string lastName = (studentData[i].substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = studentData[i].find(",", lhs);
		string emailAddress = studentData[i].substr(lhs, rhs - lhs);

		lhs = rhs + 1;
		rhs = studentData[i].find(",", lhs);
		int age = stoi(studentData[i].substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = studentData[i].find(",", lhs);
		int daysInCourse1 = stoi(studentData[i].substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = studentData[i].find(",", lhs);
		int daysInCourse2 = stoi(studentData[i].substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = studentData[i].find(",", lhs);
		int daysInCourse3 = stoi(studentData[i].substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = studentData[i].find("\0", lhs);
		string type = studentData[i].substr(lhs, rhs - lhs);
		DegreeProgram dp = DegreeProgram::SOFTWARE;
		if (type == "NETWORK") {
			dp = DegreeProgram::NETWORK;
		}
		else if (type == "SECURITY") {
			dp = DegreeProgram::SECURITY;
		}

		add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, dp);
		
	}

	this->lastIndex = 0;
	
};

Roster::~Roster() {
	cout << "Roster destructor called" << endl;
	delete[] classRosterArray;
}

void Roster::add(string studentId, string firstName, string lastName, string emailAddress, int age, 
	int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram type) {
	Student *s = new Student(studentId, firstName, lastName, emailAddress, age, 
		daysInCourse1, daysInCourse2, daysInCourse3, type);
	classRosterArray[lastIndex++] = *s;
	
	cout << endl << "Student added." << endl;
	return;
}
void Roster::remove(string studentID) {
	cout << endl;
	for (int i = 0; i < 5; ++i) {
		if (classRosterArray[i].GetStudentId() == studentID) {
			cout << "Deleting: " << classRosterArray[i].GetStudentId() << endl;
			classRosterArray[i].SetStudentId("invalid");
			return;
		}
	}
	cout << "Error: Student not found..." << endl;
	return;
}

void Roster::printAll() {
	cout << endl;
	int i = 0;
	for (int i = 0; i < 5; ++i) {
		if (classRosterArray[i].GetStudentId() != "invalid") {
			cout << "   ";
			classRosterArray[i].print();
		}
	}

	return;
}

void Roster::printInvalidEmails() {
	cout << endl << "\nPrint invalid emails: \n" << endl;
	for (int i = 0; i < 5; ++i) {
		string email = classRosterArray[i].GetEmailAddress();
		int positionAtSign = email.find('@');
		int periodAfterAtSign = email.find('.', positionAtSign);
		if (periodAfterAtSign == -1) cout << "\t" << email << endl;
		else if (email.find(' ') != -1) cout << "\t" << email << endl;
	}
	cout << endl;
	return;
}

void Roster::printAverageDaysInCourse(string studentID) {
	cout << endl;
	for (int i = 0; i < 5; ++i) {
		if (classRosterArray[i].GetStudentId() == studentID) {
			cout << "Student ID: " << classRosterArray[i].GetStudentId();
			int* tempDays = classRosterArray[i].GetDaysInCourse();
			int avgDays = 0;
			for (int j = 0; j < 3; ++j) {
				avgDays += tempDays[j];
			}
			cout << "\tAverage number of days: " << avgDays / 3 << endl << endl;
			return;
		}
	}
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
	int numberMatches = 0;
	for (int i = 0; i < 5; ++i) {
		if (classRosterArray[i].GetDegreeProgram() == degreeProgram) {
			++numberMatches;
			cout << numberMatches << "   ";
			classRosterArray[i].print();
		}
	}
	return;
}

Student Roster::findStudent(int index) {
	return classRosterArray[index];
}