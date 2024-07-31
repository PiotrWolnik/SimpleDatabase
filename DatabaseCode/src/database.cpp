#include "database.hpp"

Database::Database(std::string db_name, std::string fullpath) 
    : _name{db_name}, _fullpath{fullpath}{

}

std::string Database::getDirectory()
{
    return _fullpath;
}

Database Database::createEmpty(std::string db_name) {
    std::string basedir("databases");
    if (!fs::exists(basedir))
        fs::create_directory(basedir);
    
    std::string db_folder(basedir + "/" + db_name);
    if (!fs::exists(db_folder))
        fs::create_directory(db_folder);
    
    return Database(db_name, db_folder);
}

void Database::setKeyValue(std::string key, std::tuple<std::string, int, GameHeroes::Hero, int> user_info) {
    auto [name, age, hero, level] = user_info;
    UsersData user_data{name, age, hero, level};
    std::ofstream os;
    os.open(_fullpath + "/" + key + "_user_data.kv", std::ios::out | std::ios::trunc);
    os << user_data._data;
    os.close();
}

UsersData Database::getKeyValue(std::string key) {
    std::ifstream ifs(_fullpath + "/" + key + "_user_data.kv");
    json obj;
    ifs >> obj;
    return UsersData{obj};
}

void Database::destroy() {
    if (fs::exists(_fullpath))
        fs::remove_all(_fullpath);
}
