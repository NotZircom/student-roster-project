#pragma once
#include "degree.h"
#ifndef student
#define student
#include <iostream>
#include <string>

class Student
{
public:
	Student(std::string ID, std::string FN, std::string LN, std::string EM, int A, int D1, int D2, int D3, DegreeProgram D);
	Student();

	void setStudentID(std::string ID);
	void setFirstName(std::string FN);
	void setLastName(std::string LN);
	void setEmail(std::string EM);
	void setAge(int A);
	void setCourseDays(int D1, int D2, int D3);
	void setDegree(DegreeProgram D);
	void print();

	std::string getStudentID() const;
	std::string getFirstName() const;
	std::string getLastName() const;
	std::string getEmail() const;
	std::string getDegreeString(DegreeProgram D);

	int getAge() const;
	int getCourseDays(int D);

	DegreeProgram getDegree();


private:
	std::string studentID;
	std::string firstName;
	std::string lastName;
	std::string email;
	std::string degreeString;

	int age;
	int daysInCourse[3];
	int daysInCourse1;
	int daysInCourse2;
	int daysInCourse3;

	DegreeProgram degreeType;


	
};
#endif
