# 🎓 Student Management System (C++)

A console-based Student Management System developed in **C++** using **Object-Oriented Programming (OOP)** concepts. This application allows an administrator to manage student records efficiently with permanent file storage.

---

## 📌 Features

### 👨‍🎓 Student Management
- Add Student
- View All Students
- Search Student by Roll Number
- Update Student Details
- Delete Student

### 💾 File Handling
- Save Student Records to File
- Load Student Records Automatically
- Permanent Data Storage using `students.txt`

### 📊 Reports
- Total Number of Students
- Highest CGPA
- Lowest CGPA
- Average CGPA

### 🔍 Sorting
- Sort by Roll Number
- Sort by Name
- Sort by CGPA

### 🔒 Authentication
- Admin Login

### ✅ Validation
- Duplicate Roll Number Check
- Age Validation
- CGPA Validation

---

# 🛠 Technologies Used

- C++
- Object-Oriented Programming
- STL (Vector, Algorithm)
- File Handling (`fstream`)
- Modular Programming

---

# 📂 Project Structure

```
StudentManagementSystem/
│
├── main.cpp
├── Person.h
├── Person.cpp
├── Student.h
├── Student.cpp
├── StudentManager.h
├── StudentManager.cpp
├── LoginManager.h
├── LoginManager.cpp
├── students.txt
└── README.md
```

---

# 📚 OOP Concepts Used

### Encapsulation
- Private data members
- Public getters and setters

### Inheritance
- `Student` inherits from `Person`

### Abstraction
- Each class performs a specific responsibility

### Polymorphism
- Virtual destructor in the `Person` class

### Constructors & Destructors
- Default Constructor
- Parameterized Constructor
- Destructor

---

# 📁 Data Stored

Each student record contains:

- Roll Number
- Name
- Age
- Gender
- Department
- CGPA

---

# 🚀 How to Compile

Using **clang++**

```bash
clang++ -std=c++17 *.cpp -o program
```

Run

```bash
./program
```

---

# 📋 Main Menu

```
1. Add Student
2. View Students
3. Search Student
4. Update Student
5. Delete Student
6. Reports
7. Exit
```

---

# 💾 File Storage

Student data is stored in

```
students.txt
```

Data is automatically loaded when the program starts and saved when the program exits.

---

# 🎯 Learning Outcomes

This project demonstrates:

- Object-Oriented Programming
- Inheritance
- Encapsulation
- STL (`vector`)
- File Handling
- Searching Algorithms
- Sorting Algorithms
- Input Validation
- Modular Programming
- Console-Based Application Development

---

# 📸 Sample Output

```
=====================================
     STUDENT MANAGEMENT SYSTEM
=====================================

1. Add Student
2. View Students
3. Search Student
4. Update Student
5. Delete Student
6. Reports
7. Exit

Enter Your Choice:
```

---

# 👨‍💻 Author

**Sujith Batchu**

---

# 📄 License

This project is created for educational and learning purposes.
