#include <iostream>
#include "roster.h"
#include "student.h"
#include "degree.h"




Student::Student(std::string ID, std::string FN, std::string LN, std::string EM, int A, int D1, int D2, int D3, DegreeProgram D)
{
	setStudentID(ID);
	setFirstName(FN);
	setLastName(LN);
	setEmail(EM);
	setAge(A);
	setCourseDays(D1, D2, D3);
	setDegree(D);
}

void Student::setStudentID(std::string ID)
{
	studentID = ID;
}

void Student::setFirstName(std::string FN)
{
	firstName = FN;
}

void Student::setLastName(std::string LN)
{
	lastName = LN;
}

void Student::setEmail(std::string EM)
{
	email = EM;
}

void Student::setAge(int A)
{
	age = A;
}

void Student::setCourseDays(int D1, int D2, int D3)
{

	daysInCourse[0] = D1;
	daysInCourse[1] = D2;
	daysInCourse[2] = D3;
}

void Student::setDegree(DegreeProgram D)
{
	degreeType = D;
}

std::string  Student::getStudentID() const
{
	return studentID;
}

std::string Student::getFirstName() const
{
	return firstName;
}

std::string Student::getLastName() const
{
	return lastName;
}

std::string Student::getEmail() const
{
	return email;
}

int Student::getAge() const
{
	return age;
}

int Student::getCourseDays(int D)
{
	return daysInCourse[D - 1];
}

DegreeProgram Student::getDegree()
{
	return degreeType;
}

std::string Student::getDegreeString(DegreeProgram D)
{
	switch (D)
	{
	case SECURITY:
	{
		return "SECURITY";
	}

	case NETWORK:
	{
		return "NETWORK";
	}

	case SOFTWARE:
	{
		return "SOFTWARE";
	}
	}
}

void Student::print()
{
	std::cout << "\n" + getStudentID() + "\t First Name: " + getFirstName() + "\t Last Name: " + getLastName() + "\t Age: " + std::to_string(getAge()) + "\t Days in Course: {" + std::to_string(getCourseDays(1)) + ", " + std::to_string(getCourseDays(2)) + ", " + std::to_string(getCourseDays(3)) + "} Degree Program: " + getDegreeString(getDegree());

}


