#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include "degree.h"
using namespace std;

// Section D1 - Define Student class

class Student {
public:
	Student();
	// Section D2d - constructor using all of the input params
	Student(string studentId, string firstName, string lastName, string emailAddress, int age,
		int dIC1, int dIC2, int dIC3, DegreeProgram type);
	~Student();
	// Section D2a - declare accessors
	string GetStudentId();
	string GetFirstName();
	string GetLastName();
	string GetEmailAddress();
	int GetAge();
	int* GetDaysInCourse();
	DegreeProgram GetDegreeProgram();
	// Section D2b - declare mutators
	void SetStudentId(string studentId);
	void SetFirstName(string firstName);
	void SetLastName(string lastName);
	void SetEmailAddress(string emailAddress);
	void SetAge(int age);
	void SetDaysCourseComplete(int* daysInCourse);
	// Section D2e - print specific student data
	void print();
private:
	string studentId;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int *daysInCourse;
	DegreeProgram degreeProgram;
};

#endif