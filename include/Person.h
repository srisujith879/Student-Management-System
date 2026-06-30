#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

using namespace std;

class Person
{
private:
    string name;
    int age;
    string gender;

public:
    // Constructors
    Person();
    Person(string name, int age, string gender);

    // Setters
    void setName(string name);
    void setAge(int age);
    void setGender(string gender);

    // Getters
    string getName() const;
    int getAge() const;
    string getGender() const;

    // Display function
    void displayPerson() const;

    // Destructor
    virtual ~Person();
};

#endif