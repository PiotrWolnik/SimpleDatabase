#pragma once
#include "database.hpp"

class GroundUpDB {
public:
    GroundUpDB();

    static Database createEmpty(std::string& db_name);

    static Database loadDB(std::string& db_name);
};
