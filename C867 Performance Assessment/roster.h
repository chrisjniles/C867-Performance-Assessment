#ifndef ROSTER_H
#define ROSTER_H

#include "degree.h"
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
	void add(string studentId, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram type);
	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeProgram);
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