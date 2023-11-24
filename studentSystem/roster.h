#pragma once
#include "student.h"
class roster {
public:
	int last = -1;
	const static int studentRoster = 5;
	student* studentRosterArray[studentRoster];
	void parse(string information);
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeProgram);
	void remove(string studentID);
	~roster();
};