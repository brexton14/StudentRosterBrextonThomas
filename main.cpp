#include <iostream>
#include "student.h"
#include "roster.h"
#include "degree.h"
#include <string>
#include <array>
using namespace std;

int main()
{
    cout << "Application: Visual Studio 2022" << endl;
    cout << "Course: Scripting and Programming - Applications - C867 " << endl;
    cout << "Programming Langauge Used: C++" << endl;
    cout << "WGU Student ID:012258566" << endl;
    cout << "Name: Brexton Thomas" << endl <<endl;

    const string studentData[] =
        {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", 
         "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
         "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
         "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
         "A5,Brexton,Thomas,bth1570@wgu.edu,22,20,25,30,SOFTWARE"
        };
    const int studentDataTable = 5;
    Roster classRoster;

    for (int i = 0; i < studentDataTable; i++) classRoster.parse(studentData[i]);
    cout << "Displaying all students: " << std::endl;
    classRoster.printAll();
    cout << std::endl;

    cout << "Displaying all software students: " << std::endl;
    classRoster.printByDegreeProgram(SOFTWARE);
    cout << std::endl;

    cout << "Displaying invalid email address: " << std::endl;
    classRoster.printInvalidEmails();
    cout << std::endl;

    cout << "Displaying average days in courses: " << std::endl;
    for (int i = 0; i < studentDataTable; i++)
    {
        classRoster.printdaysInCourse(classRoster.classRosterArray[i]->getID());
    }
    cout << std::endl;

    cout << "Remove student A3." << std::endl;
    classRoster.removeStudentbyID("A3");
    cout << std::endl;

    cout << "Remove student A3." << std::endl;
    classRoster.removeStudentbyID("A3");
    cout << std::endl;



}