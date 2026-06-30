#include "StudentManager.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <algorithm>
using namespace std;

// Add Student
void StudentManager::addStudent(const Student &student)
{
    students.push_back(student);

    cout << "\nStudent Added Successfully!\n";
}

// View Students
void StudentManager::viewStudents() const
{
    cout << "\n========== Student List ==========\n";

    if (students.empty())
    {
        cout << "No students available.\n";
        return;
    }

    for (const Student &student : students)
    {
        student.displayStudent();
        cout << "----------------------------------\n";
    }
}

// Search Student
void StudentManager::searchStudent() const
{
    int rollNumber;

    cout << "\nEnter Roll Number to Search: ";
    cin >> rollNumber;

    for (const Student &student : students)
    {
        if (student.getRollNumber() == rollNumber)
        {
            cout << "\n===== Student Found =====\n";
            student.displayStudent();
            return;
        }
    }

    cout << "\nStudent Not Found!\n";
}

void StudentManager::updateStudent()
{
    int rollNumber;

    cout << "\nEnter Roll Number to Update: ";
    cin >> rollNumber;

    for (Student &student : students)
    {
        if (student.getRollNumber() == rollNumber)
        {
            string name, gender, department;
            int age;
            float cgpa;

            cin.ignore();

            cout << "\nStudent Found!\n";

            cout << "Enter New Name: ";
            getline(cin, name);

            cout << "Enter New Age: ";
            cin >> age;

            cout << "Enter New Gender: ";
            cin >> gender;

            cout << "Enter New Department: ";
            cin >> department;

            cout << "Enter New CGPA: ";
            cin >> cgpa;

            student.setName(name);
            student.setAge(age);
            student.setGender(gender);
            student.setDepartment(department);
            student.setCGPA(cgpa);

            cout << "\nStudent Updated Successfully!\n";

            return;
        }
    }

    cout << "\nStudent Not Found!\n";
}

void StudentManager::deleteStudent()
{
    int rollNumber;

    cout << "\nEnter Roll Number to Delete: ";
    cin >> rollNumber;

    for (auto it = students.begin(); it != students.end(); it++)
    {
        if (it->getRollNumber() == rollNumber)
        {
            students.erase(it);

            cout << "\nStudent Deleted Successfully!\n";

            return;
        }
    }

    cout << "\nStudent Not Found!\n";
}

void StudentManager::saveToFile()
{
    ofstream file("students.txt");

    if (!file)
    {
        cout << "Error opening file!\n";
        return;
    }

    for (const Student &student : students)
    {
        file << student.getRollNumber() << ","
             << student.getName() << ","
             << student.getAge() << ","
             << student.getGender() << ","
             << student.getDepartment() << ","
             << student.getCGPA() << endl;
    }

    file.close();

    cout << "\nStudents saved successfully!\n";
}



void StudentManager::loadFromFile()
{
    ifstream file("students.txt");

    if (!file)
    {
        return;
    }

    students.clear();

    string line;

    while (getline(file, line))
    {
        stringstream ss(line);

        string rollStr, name, ageStr, gender, department, cgpaStr;

        getline(ss, rollStr, ',');
        getline(ss, name, ',');
        getline(ss, ageStr, ',');
        getline(ss, gender, ',');
        getline(ss, department, ',');
        getline(ss, cgpaStr);

        int rollNumber = stoi(rollStr);
        int age = stoi(ageStr);
        float cgpa = stof(cgpaStr);

        Student student(name, age, gender,
                        rollNumber,
                        department,
                        cgpa);

        students.push_back(student);
    }

    file.close();
}

bool StudentManager::rollNumberExists(int rollNumber) const
{
    for (const Student &student : students)
    {
        if (student.getRollNumber() == rollNumber)
        {
            return true;
        }
    }

    return false;
}

void StudentManager::totalStudents() const
{
    cout << "\nTotal Students : " << students.size() << endl;
}

void StudentManager::highestCGPA() const
{
    if (students.empty())
    {
        cout << "\nNo students available.\n";
        return;
    }

    const Student *topper = &students[0];

    for (const Student &student : students)
    {
        if (student.getCGPA() > topper->getCGPA())
        {
            topper = &student;
        }
    }

    cout << "\n===== Highest CGPA Student =====\n";
    topper->displayStudent();
}

void StudentManager::lowestCGPA() const
{
    if (students.empty())
    {
        cout << "\nNo students available.\n";
        return;
    }

    const Student *studentLowest = &students[0];

    for (const Student &student : students)
    {
        if (student.getCGPA() < studentLowest->getCGPA())
        {
            studentLowest = &student;
        }
    }

    cout << "\n===== Lowest CGPA Student =====\n";
    studentLowest->displayStudent();
}

void StudentManager::averageCGPA() const
{
    if (students.empty())
    {
        cout << "\nNo students available.\n";
        return;
    }

    float sum = 0;

    for (const Student &student : students)
    {
        sum += student.getCGPA();
    }

    cout << "\nAverage CGPA : " << sum / students.size() << endl;
}

void StudentManager::reports() const
{
    int choice;

    do
    {
        cout << "\n========== REPORTS ==========\n";
        cout << "1. Total Students\n";
        cout << "2. Highest CGPA\n";
        cout << "3. Lowest CGPA\n";
        cout << "4. Average CGPA\n";
        cout << "5. Back\n";
        cout << "Enter Choice: ";

        cin >> choice;

        switch (choice)
        {
        case 1:
            totalStudents();
            break;

        case 2:
            highestCGPA();
            break;

        case 3:
            lowestCGPA();
            break;

        case 4:
            averageCGPA();
            break;

        case 5:
            break;

        default:
            cout << "\nInvalid Choice!\n";
        }

    } while (choice != 5);
}

void StudentManager::sortByRollNumber()
{
    sort(students.begin(), students.end(),
         [](const Student &a, const Student &b)
         {
             return a.getRollNumber() < b.getRollNumber();
         });

    cout << "\nStudents Sorted by Roll Number.\n";
}


void StudentManager::sortByCGPA()
{
    sort(students.begin(), students.end(),
         [](const Student &a, const Student &b)
         {
             return a.getCGPA() > b.getCGPA();
         });

    cout << "\nStudents Sorted by CGPA.\n";
}

void StudentManager::sortByName()
{
    sort(students.begin(), students.end(),
         [](const Student &a, const Student &b)
         {
             return a.getName() < b.getName();
         });

    cout << "\nStudents Sorted by Name.\n";
}