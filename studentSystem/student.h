#pragma once
#include <iostream>
#include <iomanip>
#include "degree.h"
using std::string;
using std::cout;

class student {
public:
	// required for specify array size
	const static int daysInCourseArraySize = 3;
private:
	// generate parameters
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	double daysInCourse[daysInCourseArraySize];
	DegreeProgram degreeProgram;
public:
	student();
	student(string studentID, string firstName, string lastName, string emailAddress, int age, double daysInCourse[], DegreeProgram degreeProgram);

	// getters
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int getAge();
	double* getDaysInCourse();
	DegreeProgram getDegreeProgram();
	
	// setters
	void setStudentID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailAddress(string emailAddress);
	void setAge(int age);
	void setDaysInCourse(double daysInCourse[]);
	void setDegreeProgram(DegreeProgram degreeProgram);

	// print information
	static void printHeader();
	void print();

	// destructor
	~student();
};