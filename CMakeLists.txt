cmake_minimum_required(VERSION 3.16)

project(StudentManagementSystem)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

# Add Crow from local folder
add_subdirectory(external/Crow)

find_package(SQLite3 REQUIRED)

add_executable(StudentManagementSystem
    src/web_main.cpp
    src/Database.cpp
    src/Routes.cpp
    src/Person.cpp
    src/Student.cpp
    src/StudentManager.cpp
    src/LoginManager.cpp
)

target_link_libraries(StudentManagementSystem
    PRIVATE
    Crow
    SQLite3::SQLite3
)