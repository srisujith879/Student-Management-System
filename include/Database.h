#ifndef DATABASE_H
#define DATABASE_H

#include <sqlite3.h>
#include <string>
#include <vector>

struct Student
{
    int roll;
    std::string name;
    int age;
    std::string gender;
    std::string department;
    float cgpa;
};


class Database
{
private:
    sqlite3* db;

public:
    Database();
    ~Database();

    bool open(const std::string& filename);
    void close();

    bool createTable();

    bool addStudent(
        int roll,
        const std::string& name,
        int age,
        const std::string& gender,
        const std::string& department,
        float cgpa
    );

    bool updateStudent(
    int roll,
    const std::string& name,
    int age,
    const std::string& gender,
    const std::string& department,
    float cgpa
);

bool login(const std::string& username,
           const std::string& password);

bool deleteStudent(int roll);

    std::vector<Student> getAllStudents();
    Student searchStudent(int roll);
};



#endif