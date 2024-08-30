#ifndef roster_h
#define roster_h
#include "student.h"
#include <string>
#include <array>

class Roster
{
public:
    int lastIndex = -1;
    const static int studentDataTable = 5;
    Student* classRosterArray[studentDataTable];
public:
    void parse(string studentDataTable);
    void add(string sID,
        string sFirstName,
        string sLastName,
        string sEmail,
        int sAge,
        int daysInCourse1,
        int daysInCourse2,
        int daysInCourse3,
        DegreeProgram dp);
    void printAll();
    void printByDegreeProgram(DegreeProgram dp);
    void printInvalidEmails();
    void printdaysInCourse(string studentID);
    bool removeStudentbyID(string studentID);
    ~Roster();
};

#endif