#ifndef STUDENT_H
#define STUDENT_H

#include "degree.h"
#include <string>
#include <iostream>
using namespace std;

// Section D1 - Create the class Student

class Student {
public:
	Student();
	Student(
		string studentId,
		string firstName,
		string lastName,
		string emailAddress,
		string age,
		int daysInCourse[],
		Degree type);
	~Student();
	// Section D2a - accessors
	string GetStudentID();
	string GetFirstName();
	string GetLastName();
	string GetEmailAddress();
	string GetAge();
	int* GetDaysInCourse();

private:

};

#endif