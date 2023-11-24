#include "roster.h"
// method to parse data
void roster::parse(string data) {
	int end = data.find(","); // find first comma before first name
	//grab student id
	string studentID = data.substr(0, end);

	int start = end + 1;
	end = data.find(",", start);
	// grab first name
	string firstName = data.substr(start, end - start);
	
	// grab last name
	start = end + 1;
	end = data.find(",", start);
	string lastName = data.substr(start, end - start);

	// grab email
	start = end + 1;
	end = data.find(",", start);
	string emailAddress = data.substr(start, end - start);

	// grab age
	start = end + 1;
	end = data.find(",", start);
	int age = stoi(data.substr(start, end - start));
	
	// grab days in course pt 1
	start = end + 1;
	end = data.find(",", start);
	int days1 = stoi(data.substr(start, end - start));

	// grab days in course pt 2
	start = end + 1;
	end = data.find(",", start);
	int days2 = stoi(data.substr(start, end - start));

	// grab days in course pt 3
	start = end + 1;
	end = data.find(",", start);
	int days3 = stoi(data.substr(start, end - start));

	// grab degree program
	start = end + 1;
	end = data.find(",", start);
	string temp = data.substr(start, end - start);

	DegreeProgram degreeProgram = SECURITY;
	if (degreeTypeStrings[1] == temp) {
		degreeProgram = NETWORK;
	}
	else if (degreeTypeStrings[2] == temp) {
		degreeProgram = SOFTWARE;
	}
	
	// add student to array
	add(studentID, firstName, lastName, emailAddress, age, days1, days2, days3, degreeProgram);
}

void roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
	// convert ints to double to put into array
	double ar1 = daysInCourse1 * 1.0;
	double ar2 = daysInCourse2 * 1.0;
	double ar3 = daysInCourse3 * 1.0;

	// puts ints into array
	double pointArray[3] = { ar1, ar2, ar3 };

	// creates a new student object and adds
	studentRosterArray[++last] = new student(studentID, firstName, lastName, emailAddress, age, pointArray, degreeProgram);
}

void roster::remove(string studentID) {
	// flag to check success
	bool flag = false;
	for (int i = 0; i <= roster::last; i++) {
		// checks for matching student ID
		if (studentRosterArray[i]->getStudentID() == studentID) {
			flag = true;
			// swaps pointer of last member and current target
			if (i < studentRoster - 1) {
				student* swap = studentRosterArray[i];
				studentRosterArray[i] = studentRosterArray[studentRoster - 1];
				studentRosterArray[studentRoster - 1] = swap;
			}
			roster::last--;
		}
	}
	if (flag) {
		cout << studentID << " was removed from the roster. The new roster is as follows: " << std::endl;
		this->printAll();
	}
	else {
		cout << studentID << " was not found." << std::endl;
	}
}

void roster::printAll() {
	student::printHeader();
	// prints out information on all students
	for (int i = 0; i <= roster::last; i++) {
		studentRosterArray[i]->print();
		cout << std::endl;
	}
}

void roster::printAverageDaysInCourse(string studentID) { 
	bool flag = false;
	// flag to check success
	for (int i = 0; i <= roster::last; i++) {
		// finds matching student
		if (studentRosterArray[i]->getStudentID() == studentID) {
			// sums days in course and averages
			cout << studentID << " has an average of ";
			cout << (studentRosterArray[i]->getDaysInCourse()[0] + studentRosterArray[i]->getDaysInCourse()[1] + studentRosterArray[i]->getDaysInCourse()[2]) / 3.0;
			cout << " days remaining in their courses." << std::endl;
			cout << std::endl;
			flag = true;
		}
	}
	// flag to declare whether a character was found
	if (!flag) {
		cout << "No student with the inputted ID was found." << std::endl;
	}
}

void roster::printInvalidEmails() {
	// flag to check success
	bool flag = false;
	for (int i = 0; i <= roster::last; i++) {
		// grab email and check for 3 conditions
		string emailAddress = (studentRosterArray[i]->getEmailAddress());
		if (!(emailAddress.find(' ') == string::npos) || emailAddress.find('@') == string::npos || emailAddress.find('.') == string::npos) {
			flag = true;
			studentRosterArray[i]->print();
			cout << std::endl;
		}
	}
	// if flag was unsuccessful, no emails
	if (!flag) {
		cout << "No invalid emails found." << std::endl;
	}
}

void roster::printByDegreeProgram(DegreeProgram degreeProgram) {
	student::printHeader();
	for (int i = 0; i <= roster::last; i++) {
		// check for matching degree programs
		if (roster::studentRosterArray[i]->getDegreeProgram() == degreeProgram) {
			studentRosterArray[i]->print();
			cout << std::endl;
		}
	}
	cout << std::endl;
}

// destructor must be called for array
roster::~roster() {
	cout << "Destructor has been called." << std::endl << std::endl;
	for (int i = 0; i < roster::studentRoster; i++) {
		cout << "Removing student #" << i + 1 << std::endl;
		delete studentRosterArray[i];
		studentRosterArray[i] = nullptr;
	}
}
