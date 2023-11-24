#include "student.h"
// parameterless constructor to set default values
student::student() {
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
	for (int i = 0; i < daysInCourseArraySize; i++) {
		this->daysInCourse[i] = 0;
	}
	this->degreeProgram = DegreeProgram::SECURITY;
}

// constructor with parameters
student::student(string studentID, string firstName, string lastName, string emailAddress, int age, double daysInCourse[], DegreeProgram degreeProgram) {
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	for (int i = 0; i < daysInCourseArraySize; i++) {
		this->daysInCourse[i] = daysInCourse[i];
	}
	this->degreeProgram = degreeProgram;
}

// destructor does nothing as nothing is dynamically created
student::~student() {}

// getters
string student::getStudentID() { return this->studentID; }
string student::getFirstName() { return this->firstName;  }
string student::getLastName() { return this->lastName; }
string student::getEmailAddress() { return this->emailAddress; }
int student::getAge() { return this->age; }
double* student::getDaysInCourse() { return this->daysInCourse; }
DegreeProgram student::getDegreeProgram() { return this->degreeProgram; }

// setters
void student::setStudentID(string studentID) { this->studentID = studentID; }
void student::setFirstName(string firstName) { this->firstName = firstName; }
void student::setLastName(string lastName) { this->lastName = lastName; }
void student::setEmailAddress(string emailAddress) { this->emailAddress = emailAddress; }
void student::setAge(int age) { this->age = age; }
void student::setDaysInCourse(double daysInCourse[]) {
	for (int i = 0; i < daysInCourseArraySize; i++) {
		this->daysInCourse[i] = daysInCourse[i];
	}
}
void student::setDegreeProgram(DegreeProgram degreeProgram) { this->degreeProgram = degreeProgram;  }

// prints a header to sort of views
void student::printHeader() {
	cout << "Output format: Student ID | First Name | Last Name | Email Address | Age | Days in Course | Degree Program\n";
}

// prints out student information
void student::print() {
	cout << this->getStudentID() << '\t';
	cout << this->getFirstName() << '\t';
	cout << this->getLastName() << '\t';
	cout << this->getEmailAddress() << '\t';
	for (int i = 0; i < 3; i++) {
		cout << this->getDaysInCourse()[i] << ',';
	}
	cout << '\t';
	cout << degreeTypeStrings[this->getDegreeProgram()] << '\t';

}