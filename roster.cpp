#include <iostream>
#include <array>
#include <string>
#include "Roster.h"

using namespace std;

/* E.  Create a Roster class (roster.cpp) by doing the following:
	1.  Create an array of pointers, classRosterArray, to hold the data provided in the "studentData Table."
	2.  Create a student object for each student in the data table and populate classRosterArray.
		a.  Parse each set of data identified in the "studentData Table."ù
		b.  Add each student object to classRosterArray.
	3.  Define the following functions:
		a.  public void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram)  that sets the instance variables from part D1 and updates the roster.
		b.  public void remove(string studentID)  that removes students from the roster by student ID. If the student ID does not exist, the function prints an error message indicating that the student was not found.
		c. public void printAll() that prints a complete tab-separated list of student data in the provided format: A1 [tab] First Name: John [tab] Last Name: Smith [tab] Age: 20 [tab]daysInCourse: {35, 40, 55} Degree Program: Security. The printAll() function should loop through all the students in classRosterArray and call the print() function for each student.
		d.  public void printAverageDaysInCourse(string studentID)  that correctly prints a student‚Äôs average number of days in the three courses. The student is identified by the studentID parameter.
		e.  public void printInvalidEmails() that verifies student email addresses and displays all invalid email addresses to the user.
	Note: A valid email should include an at sign ('@') and period ('.') and should not include a space (' ').
		f.  public void printByDegreeProgram(DegreeProgram degreeProgram) that prints out student information for a degree program specified by an enumerated type. */


Roster::Roster() {
}

/* Remove the students in the Roster */

Roster::~Roster() {
	int i = 0;
	for (i = 0; i < ROSTER_SIZE; i++) {
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
}

/* E3. a.  public void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram)
	that sets the instance variables from part D1 and updates the roster. */

void Roster::add(string studentID,
	string firstName,
	string lastName,
	string emailAddress,
	int age,
	int daysInCourse1,
	int daysInCourse2,
	int daysInCourse3,
	DegreeProgram degreeprogram) {
	int courseDays[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };

	for (int i = 0; i < ROSTER_SIZE; i++) {
		if (classRosterArray[i] == nullptr) {
			classRosterArray[i] = new Student(studentID,
				firstName,
				lastName,
				emailAddress,
				age,
				courseDays,
				degreeprogram);
			break;
		}
	}

}

/* E3. b.  public void remove(string studentID)  that removes students from the roster by
	 student ID. If the student ID does not exist, the function prints an error message
	 indicating that the student was not found. */

void Roster::remove(string studentID) {
	int i = 0;
	bool j = false;
	for (i = 0; i < ROSTER_SIZE; i++) {
		if (classRosterArray[i] == nullptr) {
		}
		else {
			if (classRosterArray[i]->getStudentID() == studentID) {
				delete classRosterArray[i];
				classRosterArray[i] = nullptr;
				j = true;
			}
		}
	}
	if (j == false) {
		cout << "ERROR - Student: " << studentID << " not found." << endl;
	}
}

/* E3. c. public void printAll() that prints a complete tab - separated list of student data in the provided format :
	A1 [tab] First Name: John [tab] Last Name: Smith [tab] Age: 20 [tab]daysInCourse: {35, 40, 55} Degree Program: Security.
	The printAll() function should loop through all the students in classRosterArray and call the print() function for each student.
	The printAll() function should loop through all the students in classRosterArray and call the print() function for each student. */

void Roster::printAll() {
	int i = 0;
	cout << "Students in this class:" << endl;
	for (i = 0; i < ROSTER_SIZE; i++) {
		if (classRosterArray[i] == nullptr) {
		}
		else {
			classRosterArray[i]->print();
		}
	}
}

/* E3. d.  public void printAverageDaysInCourse(string studentID)  that correctly prints a 
	student's average number of days in the three courses.
	The student is identified by the studentID parameter. */

void Roster::printAverageDaysInCourse(string studentID) {
	int stuIDX;

	for (int i = 0; i < ROSTER_SIZE; i++) {
		if (classRosterArray[i]->getStudentID() == studentID) {
			stuIDX = i;
		}
	}
	cout << "Student " << classRosterArray[stuIDX]->getStudentID() << " "
		<< " has averaged "
		<< classRosterArray[stuIDX]->getAverageDaysInCourses()
		<< " day(s) per course for the last three courses." << endl;
}

/* E3. e.  public void printInvalidEmails() that verifies student 
	email addresses and displays all invalid email addresses to the user. 
	Note: A valid email should include an at sign ('@') and period ('.') 
	and should not include a space (' ').*/

void Roster::printInvalidEmails() {
	int i = 0;
	cout << "Invalid email addresses:" << endl;
	for (i = 0; i < ROSTER_SIZE; i++) {
		if (classRosterArray[i]->validateEmailAddress() == 1) {
			cout << classRosterArray[i]->getEmailAddress() << endl;
		}
	}
}

/* E3. f.  public void printByDegreeProgram(DegreeProgram degreeProgram) 
	that prints out student information for a degree program specified 
	by an enumerated type. */

void Roster::printByDegreeProgram(DegreeProgram byDegreeProgram) {
	int i = 0;
	for (i = 0; i < ROSTER_SIZE; i++) {
		if (classRosterArray[i]->getDegreeProgram() == byDegreeProgram) {
			classRosterArray[i]->print();
		}
	}
}

void Roster::printByDegreeProgram() {
	int i = 0;
	int j = 0;
	for (i = 0; i < ROSTER_SIZE; i++) {
		for (j = 0; j < ROSTER_SIZE; j++) {
			if (classRosterArray[i]->getDegreeProgram() == NETWORK) {
				classRosterArray[i]->print();
			}
		}
		for (j = 0; j < ROSTER_SIZE; j++) {
			if (classRosterArray[i]->getDegreeProgram() == SECURITY) {
				classRosterArray[i]->print();
			}
		}
		for (j = 0; j < ROSTER_SIZE; j++) {
			if (classRosterArray[i]->getDegreeProgram() == SOFTWARE) {
				classRosterArray[i]->print();
			}
		}
		for (j = 0; j < ROSTER_SIZE; j++) {
			if (classRosterArray[i]->getDegreeProgram() == UNDECLARED) {
				classRosterArray[i]->print();
			}
		}
	}
}

string Roster::getSID(int studentNo)
{
	return classRosterArray[studentNo]->getStudentID();
}