
#include <string>
#include <iostream>
#include "roster.h"
using namespace std;

// Section E1 - Create Roster class
Roster::Roster(int) {
	const string studentData[] = {
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		// Section A - Modify the “studentData Table” to include your personal information as the last item
		"A5,Christopher,Niles,cniles7@wgu.edu,38,30,35,40,SOFTWARE"
	};

	this->lastIndex = 0;
	
	// Create new pointer array to hold student objects
	this->classRosterArray = new Student [5]; 
};

Roster::~Roster() {
	cout << "Roster destructor called" << endl;
	delete[] classRosterArray;
}

void Roster::add(string studentId, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram type) {
	Student *s = new Student(studentId, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, type);
	classRosterArray[lastIndex++] = *s;
	
	cout << endl << "Student added." << endl;
	return;
}
void Roster::remove(string studentID) {
	cout << endl;
	for (int i = 0; i < maxSize; ++i) {
		if (classRosterArray[i].GetStudentId() == studentID) {
			cout << "Deleting: " << classRosterArray[i].GetStudentId() << endl;
			for (; i < maxSize - 1; ++i) classRosterArray[i] = classRosterArray[i + 1];
			--maxSize;
			return;
		}
	}
	cout << "Error: Student not found..." << endl;
	return;
}

void Roster::printAll() {
	cout << endl;
	int i = 0;
	for (int i = 0; i < maxSize; ++i) {
		cout << i + 1 << "   ";
		classRosterArray[i].printStudent();
	}

	return;
}

void Roster::printInvalidEmails() {
	cout << endl << "\nPrint invalid emails: \n" << endl;
	for (int i = 0; i < maxSize; ++i) {
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
	for (int i = 0; i < maxSize; ++i) {
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
	for (int i = 0; i < maxSize; ++i) {
		if (classRosterArray[i].GetDegreeProgram() == degreeProgram) {
			++numberMatches;
			cout << numberMatches << "   ";
			classRosterArray[i].printStudent();
		}
	}
	return;
}