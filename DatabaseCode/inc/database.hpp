#pragma once

#include <fstream>
#include <filesystem>
#include <tuple>
#include "json_node.hpp"

namespace fs = std::filesystem;

namespace Database {
    class IDatabase {
    public:
        IDatabase() = default;
        virtual ~IDatabase() = default;

        virtual std::string getDirectory() = 0;

        // Key value methods
        virtual void setKeyValue(std::string key, std::tuple<std::string, int, std::string, int> user_info) = 0;  
        virtual UsersData getKeyValue(std::string key) = 0;

        virtual void destroy() = 0;
        
        static IDatabase& createEmpty(std::string& db_name);
        static IDatabase& loadDB(std::string& db_name);
    };
}
