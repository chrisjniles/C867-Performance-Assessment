#ifndef ROSTER_H
#define ROSTER_H

#include "roster.h"
#include "student.h"
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

// Section E1 - Define Roster class
class Roster {
public:
	Roster(int maxSize);
	~Roster();
	//Section E3a-e required functions
	public void add(
		string studentID,
		string firstName, string lastName,
		string emailAddress,
		int age,
		int daysInCourse1,
		int daysInCourse2,
		int daysInCourse3,
		DegreeProgram degreeprogram);
	public void remove(string studentID);
	public void printAll();
	public void printAverageDaysInCourse(string studentID);
	public void printInvalidEmails();
	public void printInvalidEmails();
private:
	int lastIndex;
	int maxSize;
	Student** students;
	string studentId;
	string firstName;
	string lastName;
	string email;
	string age;
	int* daysInCourse;
	string degreeType;
};

#endif