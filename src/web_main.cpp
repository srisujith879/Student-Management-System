#include <crow.h>
#include "Routes.h"
#include "Database.h"



int main()
{
    Database database;

    if (!database.open("../students.db"))
        return 1;

    database.createTable();

    crow::SimpleApp app;

   registerRoutes(app, database);
    app.port(18080).multithreaded().run();

    return 0;
}