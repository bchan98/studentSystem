#include "roster.h"
#include <iostream>

int main() {

	cout << "This is an assignment for C867 - Scripting and Programming: Applications, written by Brendan Chan (010555373) in C++!" << std::endl << std::endl;
	const string studentData[] = {
	"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Brendan,Chan,bchan7@wgu.edu,24,22,40,22,SOFTWARE"
	};

	roster classRoster;
	const int studentRoster = 5;

	for (int i = 0; i < studentRoster; i++) {
		classRoster.parse(studentData[i]);
	}

	cout << "Displaying all students: " << std::endl;
	classRoster.printAll();

	cout << "Printing invalid emails: " << std::endl;
	classRoster.printInvalidEmails();

	cout << "Printing average days in course: " << std::endl;
	for (int i = 0; i < studentRoster; i++) {
		string check = classRoster.studentRosterArray[i]->getStudentID();
		classRoster.printAverageDaysInCourse(check);
	}
	cout << std::endl;

	cout << "Printing by degree program: " << std::endl;
	classRoster.printByDegreeProgram(SOFTWARE);

	cout << "Removing student with ID A3: " << std::endl;
	classRoster.remove("A3");
	classRoster.remove("A3");

	return 0;
}