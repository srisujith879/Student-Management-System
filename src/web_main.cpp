#include <crow.h>
#include "Routes.h"
#include "Database.h"
#include <cstdlib>


int main()
{
    Database database;

    if (!database.open("students.db"))
        return 1;

    database.createTable();

    crow::SimpleApp app;

   registerRoutes(app, database);
    

int port = 18080;

if (const char* env = std::getenv("PORT"))
{
    port = std::stoi(env);
}

app.bindaddr("0.0.0.0")
   .port(port)
   
   .run();

    return 0;
}