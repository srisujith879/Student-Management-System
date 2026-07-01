#include "Routes.h"
#include <fstream>
#include <sstream>
#include <iostream>


std::string readFile(const std::string& filename)
{
    std::ifstream file(filename);

    if (!file)
        return "<h1>File Not Found</h1>";

    std::stringstream buffer;
    buffer << file.rdbuf();

    return buffer.str();
}


void registerRoutes(crow::SimpleApp& app, Database& database)
{
    // ---------------- Login Page ----------------
    std::cout << "registerRoutes called\n";
    
    CROW_ROUTE(app, "/static/css/style.css")
([]()
{
    crow::response res(readFile("static/css/style.css"));
    res.set_header("Content-Type", "text/css");
    return res;
});
    
    
    CROW_ROUTE(app, "/")
    ([]()
    {
        return readFile("templates/login.html");
    });

    // ---------------- Dashboard ----------------
  
    CROW_ROUTE(app, "/dashboard")
    ([]()
    {
        return readFile("templates/dashboard.html");
    });

    // ---------------- Pages ----------------

    CROW_ROUTE(app, "/addStudent")
    ([]()
    {
        return readFile("templates/addStudent.html");
    });

    CROW_ROUTE(app, "/viewStudents")
    ([]()
    {
        return readFile("templates/viewStudents.html");
    });

    CROW_ROUTE(app, "/searchStudent")
    ([]()
    {
        return readFile("templates/searchStudent.html");
    });

    CROW_ROUTE(app, "/updateStudent")
    ([]()
    {
        return readFile("templates/updateStudent.html");
    });

    CROW_ROUTE(app, "/deleteStudent")
    ([]()
    {
        return readFile("templates/deleteStudent.html");
    });

    // ---------------- Login API ----------------

    CROW_ROUTE(app, "/api/login").methods(crow::HTTPMethod::POST)
    ([&database](const crow::request& req)
    {
        auto body = crow::json::load(req.body);

        if (!body)
            return crow::response(400, "Invalid JSON");

        bool ok = database.login(
            std::string(body["username"].s()),
            std::string(body["password"].s())
        );

        if (ok)
            return crow::response(200, "Login Successful");

        return crow::response(401, "Invalid Username or Password");
    });

    

    // ---------------- Add Student ----------------

    CROW_ROUTE(app, "/api/addStudent").methods(crow::HTTPMethod::POST)
    ([&database](const crow::request& req)
    {
        auto body = crow::json::load(req.body);

        if (!body)
            return crow::response(400, "Invalid JSON");

        bool ok = database.addStudent(
            body["roll"].i(),
            std::string(body["name"].s()),
            body["age"].i(),
            std::string(body["gender"].s()),
            std::string(body["department"].s()),
            (float)body["cgpa"].d()
        );

        if (ok)
            return crow::response("Student Added Successfully");

        return crow::response("Failed to Add Student");
    });

    // ---------------- View Students ----------------

    CROW_ROUTE(app, "/api/students")
    ([&database]()
    {
        auto students = database.getAllStudents();

        crow::json::wvalue result;

        for (size_t i = 0; i < students.size(); i++)
        {
            result[i]["roll"] = students[i].roll;
            result[i]["name"] = students[i].name;
            result[i]["age"] = students[i].age;
            result[i]["gender"] = students[i].gender;
            result[i]["department"] = students[i].department;
            result[i]["cgpa"] = students[i].cgpa;
        }

        return result;
    });

    // ---------------- Search Student ----------------

    CROW_ROUTE(app, "/api/searchStudent")
    ([&database](const crow::request& req)
    {
        int roll = std::stoi(req.url_params.get("roll"));

        Student s = database.searchStudent(roll);

        crow::json::wvalue x;

        x["roll"] = s.roll;
        x["name"] = s.name;
        x["age"] = s.age;
        x["gender"] = s.gender;
        x["department"] = s.department;
        x["cgpa"] = s.cgpa;

        return x;
    });

    // ---------------- Update Student ----------------

    CROW_ROUTE(app, "/api/updateStudent").methods(crow::HTTPMethod::POST)
    ([&database](const crow::request& req)
    {
        auto body = crow::json::load(req.body);

        bool ok = database.updateStudent(
            body["roll"].i(),
            std::string(body["name"].s()),
            body["age"].i(),
            std::string(body["gender"].s()),
            std::string(body["department"].s()),
            (float)body["cgpa"].d()
        );

        if (ok)
            return crow::response("Student Updated Successfully");

        return crow::response("Update Failed");
    });

    // ---------------- Delete Student ----------------

    CROW_ROUTE(app, "/api/deleteStudent").methods(crow::HTTPMethod::POST)
    ([&database](const crow::request& req)
    {
        auto body = crow::json::load(req.body);

        if (!body)
            return crow::response(400, "Invalid JSON");

        bool ok = database.deleteStudent(body["roll"].i());

        if (ok)
            return crow::response("Student Deleted Successfully");

        return crow::response("Delete Failed");
    });
}