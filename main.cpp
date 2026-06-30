#include <iostream>
#include <string>
#include "StudentManager.h"
#include "LoginManager.h"

using namespace std;

int main()
{
    StudentManager manager;
LoginManager login;

manager.loadFromFile();

if (!login.login())
{
    return 0;
}
    int choice;

    do
    {
        cout << "\n";
cout << "=========================================================\n";
cout << "             STUDENT MANAGEMENT SYSTEM\n";
cout << "=========================================================\n";
cout << " 1. Add Student\n";
cout << " 2. View Students\n";
cout << " 3. Search Student\n";
cout << " 4. Update Student\n";
cout << " 5. Delete Student\n";
cout << " 6. Reports\n";
cout << " 7. Exit\n";
cout << "=========================================================\n";
cout << "Enter Your Choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string name, gender, department;
            int age, rollNumber;
            float cgpa;

            cin.ignore();

            cout << "\nEnter Name: ";
            getline(cin, name);

            cout << "Enter Age: ";
            cin >> age;
            if (age < 16 || age > 100)
{
    cout << "\nInvalid Age!\n";
    break;
}

            cout << "Enter Gender: ";
            cin >> gender;

            cout << "Enter Roll Number: ";
            cin >> rollNumber;
            if (rollNumber <= 0)
{
    cout << "\nInvalid Roll Number!\n";
    break;
}

            cout << "Enter Department: ";
            cin >> department;

            cout << "Enter CGPA: ";
            cin >> cgpa;

            if (cgpa < 0.0 || cgpa > 10.0)
{
    cout << "\nInvalid CGPA!\n";
    break;
}

             if (manager.rollNumberExists(rollNumber))
{
    cout << "\nRoll Number already exists!\n";
    break;
} 
Student student(name, age, gender, rollNumber, department, cgpa);

          
            
            manager.addStudent(student);

            break;
        }

        case 2:
            manager.viewStudents();
            break;

        case 3:
            manager.searchStudent();
            break;

        case 4:
    manager.updateStudent();
    break;

case 5:
    manager.deleteStudent();
    break;

case 6:
    manager.reports();
    break;

case 7:
    manager.saveToFile();

    cout << "\nStudents saved successfully.\n";
    cout << "Thank You for Using Student Management System!\n";
    break;

    cout << "\nStudents saved successfully.\n";
    cout << "Thank You for Using Student Management System!\n";
    break;

        default:
            cout << "\nInvalid Choice! Please Try Again.\n";
        }

    } while (choice != 7);

    return 0;
}