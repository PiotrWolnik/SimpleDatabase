#include "database.hpp"

std::string Database::_basedir = "databases";

Database::Database(std::string& db_name, std::string& fullpath) 
    : _name{db_name}, _fullpath{fullpath}{

}

std::string Database::getDirectory()
{
    return _fullpath;
}

Database Database::createEmpty(std::string& db_name) {
    if (!fs::exists(_basedir))
        fs::create_directory(_basedir);
    
    std::string db_folder(_basedir + "/" + db_name);
    if (!fs::exists(db_folder))
        fs::create_directory(db_folder);
    
    return Database(db_name, db_folder);
}

Database Database::loadDB(std::string& db_name) {
    if (!fs::exists(_basedir)) throw std::runtime_error("ERROR when searching for databases folder!\n");
    std::string db_folder(_basedir + "/" + db_name);
    return Database(db_name, db_folder);
}

void Database::setKeyValue(std::string key, std::tuple<std::string, int, std::string, int> user_info) {
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
