#include "groundUpDB.hpp"

GroundUpDB::GroundUpDB()
{
}

Database GroundUpDB::createEmpty(std::string &db_name)
{
    return Database::createEmpty(db_name);
}

Database GroundUpDB::loadDB(std::string &db_name)
{
    return Database::loadDB(db_name);
}
