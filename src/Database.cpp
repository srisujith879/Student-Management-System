#include "Database.h"
#include <iostream>

Database::Database()
{
    db = nullptr;
}

Database::~Database()
{
    close();
}

bool Database::open(const std::string& filename)
{
    if (sqlite3_open(filename.c_str(), &db) == SQLITE_OK)
    {
        std::cout << "Database Connected\n";
        return true;
    }

    std::cout << "Database Connection Failed\n";
    return false;
}

void Database::close()
{
    if (db != nullptr)
    {
        sqlite3_close(db);
        db = nullptr;
    }
}

bool Database::createTable()
{
     const char* sql =
        "CREATE TABLE IF NOT EXISTS students("
        "roll INTEGER PRIMARY KEY,"
        "name TEXT NOT NULL,"
        "age INTEGER,"
        "gender TEXT,"
        "department TEXT,"
        "cgpa REAL);";

    char* errMsg = nullptr;

    sqlite3_exec(db, sql, nullptr, nullptr, &errMsg);

    const char* userSql =
        "CREATE TABLE IF NOT EXISTS users("
        "username TEXT PRIMARY KEY,"
        "password TEXT);";

    sqlite3_exec(db, userSql, nullptr, nullptr, nullptr);

    sqlite3_exec(
        db,
        "INSERT OR IGNORE INTO users VALUES('admin','admin123');",
        nullptr,
        nullptr,
        nullptr
    );

    std::cout << "Tables Ready\n";

    return true;
}



bool Database::addStudent(
    int roll,
    const std::string& name,
    int age,
    const std::string& gender,
    const std::string& department,
    float cgpa)
{
    sqlite3_stmt* stmt;

    const char* sql =
        "INSERT INTO students(roll,name,age,gender,department,cgpa)"
        " VALUES(?,?,?,?,?,?);";

    if(sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK)
{
    std::cout << sqlite3_errmsg(db) << std::endl;
    return false;
}
        

    sqlite3_bind_int(stmt, 1, roll);
    sqlite3_bind_text(stmt, 2, name.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_int(stmt, 3, age);
    sqlite3_bind_text(stmt, 4, gender.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 5, department.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_double(stmt, 6, cgpa);

    int rc = sqlite3_step(stmt);

if(rc != SQLITE_DONE)
{
    std::cout << sqlite3_errmsg(db) << std::endl;
}

bool success = (rc == SQLITE_DONE);

    sqlite3_finalize(stmt);

    return success;
}

std::vector<Student> Database::getAllStudents()
{
    std::vector<Student> students;

    const char* sql =
        "SELECT roll,name,age,gender,department,cgpa FROM students;";

    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK)
        return students;

    while (sqlite3_step(stmt) == SQLITE_ROW)
    {
        Student s;

        s.roll = sqlite3_column_int(stmt, 0);

        s.name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));

        s.age = sqlite3_column_int(stmt, 2);

        s.gender = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));

        s.department = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4));

        s.cgpa = static_cast<float>(sqlite3_column_double(stmt, 5));

        students.push_back(s);
    }

    sqlite3_finalize(stmt);

    return students;
}

Student Database::searchStudent(int roll)
{
    Student s;

    const char* sql =
        "SELECT roll,name,age,gender,department,cgpa FROM students WHERE roll=?;";

    sqlite3_stmt* stmt;

    sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);

    sqlite3_bind_int(stmt,1,roll);

    if(sqlite3_step(stmt)==SQLITE_ROW)
    {
        s.roll=sqlite3_column_int(stmt,0);
        s.name=(const char*)sqlite3_column_text(stmt,1);
        s.age=sqlite3_column_int(stmt,2);
        s.gender=(const char*)sqlite3_column_text(stmt,3);
        s.department=(const char*)sqlite3_column_text(stmt,4);
        s.cgpa=sqlite3_column_double(stmt,5);
    }

    sqlite3_finalize(stmt);

    return s;
}


bool Database::updateStudent(
    int roll,
    const std::string& name,
    int age,
    const std::string& gender,
    const std::string& department,
    float cgpa)
{
    sqlite3_stmt* stmt;

    const char* sql =
        "UPDATE students SET "
        "name=?,age=?,gender=?,department=?,cgpa=? "
        "WHERE roll=?;";

    if(sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr)!=SQLITE_OK)
        return false;

    sqlite3_bind_text(stmt,1,name.c_str(),-1,SQLITE_TRANSIENT);
    sqlite3_bind_int(stmt,2,age);
    sqlite3_bind_text(stmt,3,gender.c_str(),-1,SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt,4,department.c_str(),-1,SQLITE_TRANSIENT);
    sqlite3_bind_double(stmt,5,cgpa);
    sqlite3_bind_int(stmt,6,roll);

    bool ok=(sqlite3_step(stmt)==SQLITE_DONE);

    sqlite3_finalize(stmt);

    return ok;
}

bool Database::deleteStudent(int roll)
{
    sqlite3_stmt* stmt;

    const char* sql = "DELETE FROM students WHERE roll=?;";

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK)
        return false;

    sqlite3_bind_int(stmt, 1, roll);

    bool ok = (sqlite3_step(stmt) == SQLITE_DONE);

    sqlite3_finalize(stmt);

    return ok;


}
bool Database::login(const std::string& username,
                     const std::string& password)
{
    sqlite3_stmt* stmt;

    const char* sql =
        "SELECT * FROM users WHERE username=? AND password=?;";

    sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);

    sqlite3_bind_text(stmt,1,username.c_str(),-1,SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt,2,password.c_str(),-1,SQLITE_TRANSIENT);

    bool ok = (sqlite3_step(stmt) == SQLITE_ROW);

    sqlite3_finalize(stmt);

    return ok;
}

