#include "degree.h"
#include "roster.h"
#include "student.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
	int maxSize = 5;

	//Print out header information; course name and information as well as student ID and name.
	cout << "C867-Scripting & Programming: Applications" << endl
		<< "Language:	C++" << endl
		<< "Student ID:	000838847" << endl
		<< "Name:		Christopher Niles" << endl;

	Roster* classRoster = new Roster(maxSize);   //create classRoster, add each student to classRoster

	classRoster->printAll();

	classRoster->printInvalidEmails();

	for (int i = 0; i < maxSize; ++i) { //loop through printAverageDaysInCourse()
		ostringstream idOSS;
		idOSS << "A" << i + 1;
		classRoster->printAverageDaysInCourse(idOSS.str());
	}

	classRoster->remove("A3");

	classRoster->printAll();

	classRoster->remove("A3");

	char exitSign = 'a';
	while (exitSign != 'q') {


		cout << endl << "enter 'q' to quit...";
		cin >> exitSign;
		cout << endl << endl;
	}

	return 0;

}