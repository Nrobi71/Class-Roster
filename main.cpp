#include <iostream>
#include <sstream>
#include <string>
#include "Roster.h"

using namespace std;

/* F1. Print out to the screen, via your application, the course title,
	the programming language used, your WGU student ID, and your name. */

void courseHeader() {
	cout << "Scripting and Programming - Applications - C867" << endl;
	cout << "Language: C++" << endl;
	cout << "Name: Nyssa Robinson" << endl;
	cout << "Student ID: #000916880" << endl << endl;
}

int main() {
	const int ROSTER_SIZE = 5;
	const string studentData[5] =
	{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Nyssa,Robinson,nrobi71@wgu.edu,30,14,20,45,SOFTWARE" }; /* << A. Modify the “studentData Table”
	to include your personal information as the last item. */

	DegreeProgram degreeProgram;

	courseHeader();

/* F2.Create an instance of the Roster class called classRoster. */

	Roster classRoster;

	string studentID;

/* F3.Add each student to classRoster.
	string input = studentData[i]; */

	cout << "Adding Students to Roster: ";
	for (int i = 0; i < sizeof(studentData) / sizeof(studentData[i]); i++) {
		string input = studentData[i];
		istringstream ss(input);
		string token;
		string rAddDat[9];

		int j = 0;
		while (getline(ss, token, ',')) {
			rAddDat[j] = token;
			j += 1;
		}

		if (rAddDat[8] == "SECURITY") {
			degreeProgram = SECURITY;
		}
		else if (rAddDat[8] == "NETWORK") {
			degreeProgram = NETWORK;
		}
		else if (rAddDat[8] == "SOFTWARE") {
			degreeProgram = SOFTWARE;
		}
		else {
			degreeProgram = UNDECLARED;
		}
		cout << "Calling add for " << rAddDat[0] << ", ";
		classRoster.add(rAddDat[0],
			rAddDat[1],
			rAddDat[2],
			rAddDat[3],
			std::stoi(rAddDat[4]),
			std::stoi(rAddDat[5]),
			std::stoi(rAddDat[6]),
			std::stoi(rAddDat[7]),
			degreeProgram);
	}
	cout << endl;

/* F4. Convert the following pseudo code to complete the rest of the  main() function: 
	classRoster.printAll();
	classRoster.printInvalidEmails(); */

	cout << endl << "Calling printAll():" << endl;
	classRoster.printAll();

	cout << endl << "Calling printInvalidEmails():" << endl;
	classRoster.printInvalidEmails();

/* loop through classRosterArrayand for each element:
	classRoster.printAverageDaysInCourse(//current_object's student id); 
	Note: For the current_object's student id, usa an accessor (i.e. getter) for the classRosterArray to access the student id.

		classRoster.printByDegreeProgram(SOFTWARE);
		classRoster.remove("A3");
		classRoster.printAll();
		classRoster.remove("A3"); */

	cout << endl << "Calling printAverageDaysInCourse() for each student:" << endl;
	for (int i = 0; i < ROSTER_SIZE; i++) {
		classRoster.printAverageDaysInCourse(classRoster.getSID(i));
	}

	cout << endl << "Calling printByDegreeProgram(SOFTWARE):" << endl;
	classRoster.printByDegreeProgram(SOFTWARE);

	cout << endl << "Calling remove(A3):" << endl;
	classRoster.remove("A3");

	cout << endl << "Calling printAll():" << endl;
	classRoster.printAll();

	cout << endl << "Calling remove(A3):" << endl;
	classRoster.remove("A3");
	//expected: the above line should print a message saying such a student with this ID was not found.
}

/*	F5. Implement the destructor to release the memory that was allocated dynamically in Roster.
	
	G.  Demonstrate professional communication in the content and presentation of your submission.*/