#ifndef ROUTES_H
#define ROUTES_H

#include <crow.h>
#include "Database.h"

void registerRoutes(crow::SimpleApp& app, Database& database);

#endif