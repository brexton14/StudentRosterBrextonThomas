#ifndef student_h
#define student_h
#include <iostream>
#include <iomanip>
#include "degree.h"
using std::string;
using std::endl;
using std::cout;

class Student
{
public:
    const static int daysArray = 3;
private:
    string studentID;
    string firstname;
    string lastname;
    string emailaddress;
    int age;
    int days[daysArray];
    DegreeProgram degreeprogram;
public:
    Student();
    Student(string studentID ,string firstname, string lastname, string emailAddress, int age, int days[], DegreeProgram degreeprogram);
    ~Student();

    string getID();
    string getfirstName();
    string getlastName();
    string getEmail();
    int getAge();
    int* getDays();
    DegreeProgram getdegreeProgram();
    
    void setID(string studentID);
    void setfirstName(string firstname);
    void setlastName(string lastname);
    void setEmail(string emailaddress);
    void setAge(int age);
    void setDays(int days[]);
    void setDegree(DegreeProgram degreeprogram);

    static void printHeader();

    void print();
};


#endif
