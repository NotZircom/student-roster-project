#include <iostream>
#include <array>
#include <sstream>
#include "roster.h"
#include "student.h"
#include "degree.h"

	Roster::Roster(const std::string studentData[5])
	{
		classRosterArray = new Student* [1];
		lastAdded = -1;
		currentRosterSize = 0;

		for (int i = 0; i < 5; i++)
		{
			createStudent(studentData[i]);
		}

	}

	Roster::~Roster() {
		delete[] classRosterArray;
	}

	void Roster::createStudent(std::string studentData) 
	{
		std::istringstream inSS(studentData);
		std::vector<std::string> SD;

		for (int i = 0; i < 9; ++i)
		{
			std::string tempS;
			std::getline(inSS, tempS, ',');
			SD.push_back(tempS);
		}

		tempStudentID = SD[0];
		tempFirstName = SD[1];
		tempLastName = SD[2];
		tempEmail = SD[3];
		tempAge = std::stoi(SD[4]);
		tempDaysInCourse1 = std::stoi(SD[5]);
		tempDaysInCourse2 = std::stoi(SD[6]);
		tempDaysInCourse3 = std::stoi(SD[7]);
		if (SD[8] == "NETWORK")
			tempDegreeType = NETWORK;
		if (SD[8] == "SECURITY")
			tempDegreeType = SECURITY;
		if (SD[8] == "SOFTWARE")
			tempDegreeType = SOFTWARE;

		add(tempStudentID, tempFirstName, tempLastName, tempEmail, tempAge, tempDaysInCourse1, tempDaysInCourse2, tempDaysInCourse3, tempDegreeType);

		return;
	}

	void Roster::add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1,
		int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram)
	{
		resizeRoster(1);
		classRosterArray[lastAdded + 1] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeprogram);
		lastAdded++;
		currentRosterSize++;
			
	}

	void Roster::printAll()
	{
		for (int i = 0; i < currentRosterSize; i++)
		{
			classRosterArray[i]->print();
		}
		std::cout << "\n";
	}

	void Roster::resizeRoster(int A)
	{
		Student** tempStudents = new Student * [currentRosterSize + A];
		for (int i = 0; i < currentRosterSize; i++) tempStudents[i] = classRosterArray[i];

		delete[] classRosterArray;

		classRosterArray = new Student * [currentRosterSize + A];
		for (int i = 0; i < currentRosterSize + A; i++)
			classRosterArray[i] = tempStudents[i];
	}

	void Roster::remove(std::string studentID)
	{
		for (int i = 0; i < currentRosterSize; i++)
		{
			if (studentID == classRosterArray[i]->getStudentID())
			{
				for (int j = i; j < currentRosterSize - 1; j++)
				{
					classRosterArray[j] = classRosterArray[j + 1];
				}
				resizeRoster(-1);
				lastAdded--;
				currentRosterSize--;
				return;
			}
		}
		std::cout << "Error, student with ID " + studentID + " not found.";
		return;
	}

	//note: I've implemented the requirements as given, which will not always identify valid email addresses,
	//ex: john.smith@examplecom would read as valid because it has an "@" and a "." and no spaces.
	//however the requirements as given will correctly identify all of the email addresses in the current data set so I'm leaving it as is.
	void Roster::printInvalidEmails()
	{
		int spaceFound;
		int atFound;
		int periodFound;
		std::cout << "\nInvalid Emails:\n";
		for(int i = 0; i < currentRosterSize; i++)
		{
			spaceFound = classRosterArray[i]->getEmail().find(" ");
			atFound = classRosterArray[i]->getEmail().find("@");
			periodFound = classRosterArray[i]->getEmail().find(".");

			if (periodFound != -1 && atFound != -1 && spaceFound == -1)
			{ }
			else
			{
				std::cout << classRosterArray[i]->getEmail() + "\n";
			}
		}
		std::cout << "\n";
	}

	void Roster::printByDegreeProgram(DegreeProgram D)
	{
		for (int i = 0; i < currentRosterSize; i++)
		{
			if (getDegreeString(D) == classRosterArray[i]->getDegreeString(classRosterArray[i]->getDegree()))
				classRosterArray[i]->print();

		}
		
	}

	std::string Roster::getDegreeString(DegreeProgram D)
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

	void Roster::printAverageDaysInCourse(std::string studentID)
	{
		for (int i = 0; i < currentRosterSize; i++)
			if (classRosterArray[i]->getStudentID() == studentID)
				std::cout << "\nAverage Days in course for Student " + studentID + ": " + std::to_string(((classRosterArray[i]->getCourseDays(1) + classRosterArray[i]->getCourseDays(2) + classRosterArray[i]->getCourseDays(3)) / 3));
	}

	int Roster::getCurrentRosterSize()
	{
		return currentRosterSize;
	}

	Student* Roster::getCurrentStudent(int I)
	{
		return classRosterArray[I];
	}