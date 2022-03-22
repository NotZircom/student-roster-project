// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "degree.h"
#include "roster.h"
#include "student.h"


int main()
{
	const std::string studentData[5] =
	{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Forrest,Vasilinda,forrestvasilinda@gmail.com,26, 25,42,69,SOFTWARE"
	};

	std::cout << "SCRIPTING AND PROGRAMMING - APPLICATIONS - C867 | C++ | 001467270 | Forrest Vasilinda\n";
	Roster classRoster(studentData);
	std::cout << "\nAll Students:";
	classRoster.printAll();
	classRoster.printInvalidEmails();
	std::cout << "Average Course Length for all students:";
	for (int i = 0; i < classRoster.getCurrentRosterSize(); i++)
	{
		classRoster.printAverageDaysInCourse(classRoster.getCurrentStudent(i)->getStudentID());
	}
	std::cout << "\n\nAll Software Students:";
	classRoster.printByDegreeProgram(SOFTWARE);
	classRoster.remove("A3");
	std::cout << "\n\nAll Students";
	classRoster.printAll();
	std::cout << "\n";
	classRoster.remove("A3");


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
