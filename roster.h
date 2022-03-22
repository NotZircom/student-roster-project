#pragma once
#include "degree.h"
#include "student.h"
#ifndef roster
#define roster
#include <iostream>
#include <string>
#include <vector>
class Roster
{
public:

	Roster(const std::string studentData[5]);
	~Roster();

	void remove(std::string studentID);
	void printAll();
	void createStudent(std::string studentData);
	void add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);
	void printAverageDaysInCourse(std::string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeProgram);
	void resizeRoster(int A);
	
	int getCurrentRosterSize();

	Student* getCurrentStudent(int I);

	std::string getDegreeString(DegreeProgram D);

private:

	Student **classRosterArray;

	std::string tempStudentID;
	std::string tempFirstName;
	std::string tempLastName;
	std::string tempEmail;

	int tempAge;
	int lastAdded;
	int currentRosterSize;
	int tempDaysInCourse1;
	int tempDaysInCourse2;
	int tempDaysInCourse3;

	DegreeProgram tempDegreeType;

};
#endif
