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

Roster::~Roster() {
	cout << "Roster destructor called" << endl;
	delete[] students;
}

void Roster::add(string studentId, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram type) {
	this->daysInCourse = new int[3];
	this->daysInCourse[0] = daysInCourse1;
	this->daysInCourse[1] = daysInCourse2;
	this->daysInCourse[2] = daysInCourse3;
	this->age = to_string(age);

	Student** tempStudents = new Student * [maxSize];
	for (int i = 0; i < maxSize; i++) tempStudents[i] = students[i];
	delete[] students;
	students = new Student * [++maxSize];
	for (int i = 0; i < maxSize - 1; i++) students[i] = tempStudents[i];
	
	cout << endl << "Student added." << endl;
	return;
}
void Roster::remove(string studentID) {
	cout << endl;
	for (int i = 0; i < maxSize; ++i) {
		if (students[i]->GetStudentId() == studentID) {
			cout << "Deleting: " << students[i]->GetStudentId() << endl;
			for (; i < maxSize - 1; ++i) students[i] = students[i + 1];
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
		students[i]->Print();
	}

	return;
}

void Roster::printInvalidEmails() {
	cout << endl << "\nPrint invalid emails: \n" << endl;
	for (int i = 0; i < maxSize; ++i) {
		string email = students[i]->GetEmailAddress();
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
		if (students[i]->GetStudentId() == studentID) {
			cout << "Student ID: " << students[i]->GetStudentId();
			int* tempDays = students[i]->GetDaysInCourse();
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
		if (students[i]->GetDegreeProgram() == degreeProgram) {
			++numberMatches;
			cout << numberMatches << "   ";
			students[i]->Print();
		}
	}
	return;
}