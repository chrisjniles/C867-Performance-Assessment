#include "roster.h"

// Section E1 - Create Roster class

Roster::Roster(int maxSize) {
	const string studentData[] = {
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		// Section A - Modify the “studentData Table” to include your personal information as the last item
		"A5,Christopher,Niles,cniles7@wgu.edu,38,30,35,40,SOFTWARE"
	};

	this->lastIndex = -1;
	this->maxSize = maxSize;
	// Create new pointer array to hold student objects
	this->students = new Student * [maxSize]; 
};


