#include <iostream>
#include <string>
#include "degree.h"
#include "student.h"
#include "roster.h"
#include <array>
#include <string>
using namespace std;

void Roster::parse(string studentData) {

    int rhs = studentData.find(',');
    string sID = studentData.substr(0, rhs);

    int lhs = rhs + 1;
    rhs = studentData.find(',', lhs);
    string sFirstName = studentData.substr(lhs, rhs -lhs);

    lhs = rhs + 1;
    rhs = studentData.find(',', lhs);
    string sLastName = studentData.substr(lhs, rhs -lhs);

    lhs = rhs + 1;
    rhs = studentData.find(',', lhs);
    string sEmail = studentData.substr(lhs, rhs -lhs);
    
    lhs = rhs + 1;
    rhs = studentData.find(',', lhs);
    int sAge = stoi(studentData.substr(lhs, rhs -lhs));

    lhs = rhs + 1;
    rhs = studentData.find(',', lhs);
    int daysInCourse1 = stod(studentData.substr(lhs, rhs-lhs));

    lhs = rhs + 1;
    rhs = studentData.find(',', lhs);
    int daysInCourse2 = stod(studentData.substr(lhs, rhs-lhs));

    lhs = rhs + 1;
    rhs = studentData.find(',', lhs);
    int daysInCourse3 = stod(studentData.substr(lhs, rhs-lhs));

    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);

    DegreeProgram dp = SECURITY;

    if (studentData.at(lhs) == 'S' && studentData.at(lhs + 1) == 'E') dp = SECURITY;
    else if (studentData.at(lhs) == 'S' && studentData.at(lhs + 1) == 'O') dp = SOFTWARE;
    else if  (studentData.at(lhs) == 'N') dp == NETWORK;

    add(sID, sFirstName, sLastName, sEmail, sAge, daysInCourse1, daysInCourse2, daysInCourse3, dp);
    
}

void Roster::add(string studentID, string firstName, string lastName, string emailaddress, int age, int DaysinCourse1, int DaysinCourse2, int DaysinCourse3, DegreeProgram dp)
{
    int darr[3] = {DaysinCourse1, DaysinCourse2, DaysinCourse3};
    classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailaddress, age, darr, dp);
}

void Roster::printAll()
{
    Student::printHeader();
    for (int i = 0; i <= Roster::lastIndex; i++) Roster::classRosterArray[i]->print();
}

void Roster::printInvalidEmails()
{
    bool any = false;
    for (int i = 0; i <= Roster::lastIndex; i++)
    {
        string emailaddress = (classRosterArray[i]->getEmail());
        if ((emailaddress.find("@") == string::npos) || (emailaddress.find(" ") != string::npos) || (emailaddress.find(".") == string::npos))
        {
            any = true;
            cout << "Email:" << emailaddress << " First Name:" << classRosterArray[i]->getfirstName() << std::endl;
        }
    }
    if (!any) cout << "NONE" << std::endl;
}

void Roster::printdaysInCourse(string studentID)
{
    for(int i = 0; i <= Roster::lastIndex; i++)
    {
        if (classRosterArray[i]->getID()==studentID)
        {
            cout << studentID << ",";
            cout << (classRosterArray[i]->getDays()[0]+
                    classRosterArray[i]->getDays()[1]+
                    classRosterArray[i]->getDays()[2])/3 << std::endl;
                        
        }
    }
}

void Roster::printByDegreeProgram(DegreeProgram dp)
{
    Student::printHeader();
    for (int i = 0; i <= Roster::lastIndex; i++){
            if (Roster::classRosterArray[i]->getdegreeProgram() == dp) classRosterArray[i]->print();
        }
        cout << std::endl;
}

bool Roster::removeStudentbyID(string studentID)
{
    bool success = false;
    for (int i = 0; i <= Roster::lastIndex; i++)
    {
        if (classRosterArray[i]->getID() == studentID)
        {
            success = true;
            if (i < studentDataTable - 1)
            {
                Student* temp = classRosterArray[i];
                classRosterArray[i] = classRosterArray[studentDataTable - 1];
                classRosterArray[studentDataTable - 1] = temp;
            }    
            Roster::lastIndex--;
        }
        
    }
    if (success)
    {
        cout << studentID << " Removed from Roster." << std::endl << std::endl;
        this->printAll();
    }
    else cout << studentID << " was not found" << std::endl << std::endl;
    return 0;
}

Roster::~Roster()
{
    cout << "Destructor Called" << std::endl << std::endl;
    for (int i = 0; i < studentDataTable; i++)
    {
        cout << "Removing student from roster StudentID: A" << i + 1 << std::endl;
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
    }
}