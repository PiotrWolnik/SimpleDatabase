#pragma once

#include <fstream>
#include <filesystem>
#include <tuple>
#include "json_node.hpp"

namespace fs = std::filesystem;

class Database {
public:
    Database(std::string db_name, std::string fullpath);

    std::string getDirectory();

    // Key value methods
    void setKeyValue(std::string key, std::tuple<std::string, int, GameHeroes::Hero, int> user_info);  
    UsersData getKeyValue(std::string key);

    static Database createEmpty(std::string db_name);
    void destroy();
    
private:
    std::string _name;
    std::string _fullpath;
};
