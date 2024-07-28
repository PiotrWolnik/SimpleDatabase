#include "groundUpDB.hpp"

GroundUpDB::GroundUpDB()
{
}

Database GroundUpDB::createEmpty(std::string &db_name)
{
    return Database::createEmpty(db_name);
}
