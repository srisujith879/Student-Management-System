#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"

class Student : public Person
{
private:
    int rollNumber;
    string department;
    float cgpa;

public:
    // Constructors
    Student();
    Student(string name, int age, string gender,
            int rollNumber,
            string department,
            float cgpa);

    // Setters
    void setRollNumber(int rollNumber);
    void setDepartment(string department);
    void setCGPA(float cgpa);

    // Getters
    int getRollNumber() const;
    string getDepartment() const;
    float getCGPA() const;

    // Display Student
    void displayStudent() const;

    // Destructor
    ~Student();
};

#endif