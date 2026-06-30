#include "LoginManager.h"
#include <iostream>

using namespace std;

bool LoginManager::login()
{
    string username;
    string password;

    cout << "\n========== LOGIN ==========\n";

    cout << "Username: ";
    cin >> username;

    cout << "Password: ";
    cin >> password;

    if (username == "admin" && password == "admin123")
    {
        cout << "\nLogin Successful!\n";
        return true;
    }

    cout << "\nInvalid Username or Password!\n";

    return false;
}