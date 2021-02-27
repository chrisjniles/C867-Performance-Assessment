#ifndef STUDENT_H
#define STUDENT_H

#include "degree.h"
#include <string>
#include <iostream>
using namespace std;

// Section D1 - Define Student class

class Student {
public:
	Student();
	// Section D2d - constructor using all of the input params
	Student(string studentId,
		string firstName,
		string lastName,
		string emailAddress,
		string age,
		int daysInCourse[],
		DegreeProgram type);
	~Student();
	// Section D2a - declare accessors
	string GetStudentId();
	string GetFirstName();
	string GetLastName();
	string GetEmailAddress();
	string GetAge();
	int* GetDaysInCourse();
	DegreeProgram GetDegreeProgram();
	// Section D2b - declare mutators
	void SetStudentId(string studentId);
	void SetFirstName(string firstName);
	void SetLastName(string lastName);
	void SetEmailAddress(string emailAddress);
	void SetAge(string age);
	void SetDaysCourseComplete(int daysInCourse[]);
	// Section D2e - print specific student data
	void printStudent();
private:
	string studentId;
	string firstName;
	string lastName;
	string emailAddress;
	string age;
	int *daysInCourse;
	DegreeProgram degreeType;
};

#endif