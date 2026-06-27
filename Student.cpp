#include "Student.h"
#include <iostream>

using namespace std;

// Default Constructor
Student::Student()
{
    rollNumber = 0;
    department = "";
    cgpa = 0.0;
}

// Parameterized Constructor
Student::Student(string name, int age, string gender,
                 int rollNumber,
                 string department,
                 float cgpa)
    : Person(name, age, gender)
{
    this->rollNumber = rollNumber;
    this->department = department;
    this->cgpa = cgpa;
}

// Setters
void Student::setRollNumber(int rollNumber)
{
    this->rollNumber = rollNumber;
}

void Student::setDepartment(string department)
{
    this->department = department;
}

void Student::setCGPA(float cgpa)
{
    this->cgpa = cgpa;
}

// Getters
int Student::getRollNumber() const
{
    return rollNumber;
}

string Student::getDepartment() const
{
    return department;
}

float Student::getCGPA() const
{
    return cgpa;
}

// Display
void Student::displayStudent() const
{
    displayPerson();

    cout << "Roll No    : " << rollNumber << endl;
    cout << "Department : " << department << endl;
    cout << "CGPA       : " << cgpa << endl;
}

// Destructor
Student::~Student()
{
}

