#include <iostream>
#include <string>
#include "degree.h"
#include "student.h"
#include "roster.h"


Student::Student()
{
    this->studentID = ""; 
    this->firstname = "";
    this->lastname = "";
    this->emailaddress = "";
    this->age = 0;
    for (int i=0; i < daysArray; i++) this->days[i] = 0;
    this->degreeprogram = DegreeProgram:: SECURITY;
}

Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int days[], DegreeProgram degreeprogram)
{
    this->studentID = studentID;
    this->firstname = firstName;
    this->lastname = lastName;
    this->emailaddress = emailAddress;
    this->age = age;
    for (int i = 0; i < daysArray; i++) this->days[i] = days[i];
    this->degreeprogram = degreeprogram;
}

Student::~Student() {};

string Student::getID() {return this->studentID; }
string Student::getfirstName() {return this->firstname; }
string Student::getlastName() {return this->lastname; }
string Student::getEmail() {return this->emailaddress; }
int Student::getAge() {return this->age; }
int* Student::getDays() {return this->days; }
DegreeProgram Student:: getdegreeProgram() {return this->degreeprogram; }


void Student::setID(string ID) {this->studentID = ID; }
void Student::setfirstName(string firstname) {this->firstname = firstname;}
void Student::setlastName(string lastname) {this->lastname = lastname;}
void Student::setEmail(string emailAddress) {this->emailaddress = emailAddress;}
void Student::setAge(int age) {this->age = age;}
void Student::setDays(int days[])
{
    for (int i = 0; i < daysArray; i++) this->days[i] = days[i];
}
void Student::setDegree(DegreeProgram degreeprogram) {this->degreeprogram = degreeprogram; }

void Student::printHeader()
{
    
    cout << "Output format:" << endl <<"StudentID | FirstName | LastName | Email | Age | #ofcoursedays | DegreeProgram\n";
}

void Student::print()
{
    cout << this->getID() << '\t';
    cout << this->getfirstName() << '\t';
    cout << this->getlastName() << '\t';
    cout << this->getEmail() << '\t';
    cout << this->getAge() << '\t';
    cout << this->getDays()[0] << ',';
    cout << this->getDays()[1] << ',';
    cout << this->getDays()[2] << '\t';
    cout << DegreeProgramStrings[this->getdegreeProgram()] << '\n';
}