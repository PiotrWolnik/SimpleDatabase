#pragma once
#include "database.hpp"

namespace Database {
    class GroundUpDB {
    public:
        GroundUpDB();

        static const std::unique_ptr<IDatabase> createEmpty(std::string& db_name);

        static const std::unique_ptr<IDatabase> loadDB(std::string& db_name);
    };   
}
