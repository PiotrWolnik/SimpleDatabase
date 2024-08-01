#include "groundUpDB.hpp"
#include "extensions/embedded_database.hpp"

using namespace EmbeddedDatabase;

GroundUpDB::GroundUpDB()
{
}

const std::unique_ptr<IDatabase> GroundUpDB::createEmpty(std::string &db_name)
{
    return EmbeddedDB::createEmpty(db_name);
}

const std::unique_ptr<IDatabase> GroundUpDB::loadDB(std::string &db_name)
{
    return EmbeddedDB::loadDB(db_name);
}
