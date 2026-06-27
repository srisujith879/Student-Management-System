#ifndef STUDENTMANAGER_H
#define STUDENTMANAGER_H

#include <vector>
#include "Student.h"

using namespace std;

class StudentManager
{
private:
    vector<Student> students;

public:
    void addStudent(const Student &student);
    void viewStudents() const;
    void searchStudent() const;
    void updateStudent();
    void deleteStudent();

    void saveToFile();
void loadFromFile();
void reports() const;
void totalStudents() const;
void highestCGPA() const;
void lowestCGPA() const;
void averageCGPA() const;
void sortByRollNumber();
void sortByName();
void sortByCGPA();

bool rollNumberExists(int rollNumber) const;
};

#endif