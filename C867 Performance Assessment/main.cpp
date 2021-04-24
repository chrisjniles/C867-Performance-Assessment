
#include <iostream>
#include <string>
#include "roster.h"

using namespace std;

int main() {
	
	//Print out header information; course name and information as well as student ID and name.
	
	cout << "C867-Scripting & Programming: Applications" << endl
		<< "Language:	C++" << endl
		<< "Student ID:	000838847" << endl
		<< "Name:		Christopher Niles" << endl;

	 
	Roster* classRoster = new Roster(5);   //create classRoster, add each student to classRoster
	

	classRoster->printAll();

	
	
	classRoster->printInvalidEmails();

	for (int i = 0; i < 5; ++i) { //loop through printAverageDaysInCourse()
		Student s = classRoster->findStudent(i);
		classRoster->printAverageDaysInCourse(s.GetStudentId());
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