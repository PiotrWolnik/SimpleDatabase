#include "database.hpp"
#include "extensions/embedded_database.hpp"

using namespace EmbeddedDatabase;

class EmbeddedDB::ImplDB : public IDatabase {
public:
    ImplDB(std::string& db_name, std::string& fullpath);
    
    std::string getDirectory() override;

    void setKeyValue(std::string key, std::tuple<std::string, int, std::string, int> user_info) override;  
    UsersData getKeyValue(std::string key) override;

    void destroy() override;
    
    static const std::unique_ptr<IDatabase> createEmpty(std::string& db_name);
    static const std::unique_ptr<IDatabase> loadDB(std::string& db_name);

    ~ImplDB() = default;
private:
    std::string _name;
    std::string _fullpath;
    static std::string _basedir;
};

std::string EmbeddedDB::ImplDB::_basedir = "databases";

EmbeddedDB::EmbeddedDB(std::string& db_name, std::string& fullpath)
    : _impl_db{std::make_unique<EmbeddedDB::ImplDB>(db_name, fullpath)} {}

EmbeddedDB::ImplDB::ImplDB(std::string& db_name, std::string& fullpath)
    : _name{db_name}, _fullpath{fullpath}{

}

std::string EmbeddedDB::ImplDB::getDirectory()
{
    return _fullpath;
}

const std::unique_ptr<IDatabase> EmbeddedDB::ImplDB::createEmpty(std::string& db_name) {
    if (!fs::exists(_basedir))
        fs::create_directory(_basedir);
    
    std::string db_folder(_basedir + "/" + db_name);
    if (!fs::exists(db_folder))
        fs::create_directory(db_folder);
    
    return std::make_unique<EmbeddedDB::ImplDB>(db_name, db_folder);
}

const std::unique_ptr<IDatabase> EmbeddedDB::ImplDB::loadDB(std::string& db_name) {
    if (!fs::exists(_basedir)) throw std::runtime_error("ERROR when searching for databases folder!\n");
    std::string db_folder(_basedir + "/" + db_name);
    return std::make_unique<EmbeddedDB::ImplDB>(db_name, db_folder);
}

void EmbeddedDB::ImplDB::setKeyValue(std::string key, std::tuple<std::string, int, std::string, int> user_info) {
    auto [name, age, hero, level] = user_info;
    UsersData user_data{name, age, hero, level};
    std::ofstream os;
    os.open(_fullpath + "/" + key + "_user_data.kv", std::ios::out | std::ios::trunc);
    os << user_data._data;
    os.close();
}

UsersData EmbeddedDB::ImplDB::getKeyValue(std::string key) {
    std::ifstream ifs(_fullpath + "/" + key + "_user_data.kv");
    json obj;
    ifs >> obj;
    return UsersData{obj};
}

void EmbeddedDB::ImplDB::destroy() {
    if (fs::exists(_fullpath))
        fs::remove_all(_fullpath);
}

std::string EmbeddedDB::getDirectory() {
    return _impl_db->getDirectory();
}

void EmbeddedDB::setKeyValue(std::string key, std::tuple<std::string, int, std::string, int> user_info) {
    _impl_db->setKeyValue(key, user_info);
}

UsersData EmbeddedDB::getKeyValue(std::string key) {
    return _impl_db->getKeyValue(key);
}

void EmbeddedDB::destroy() {
    _impl_db->destroy();
}

const std::unique_ptr<IDatabase> EmbeddedDB::createEmpty(std::string& db_name) {
    return EmbeddedDB::ImplDB::createEmpty(db_name);
}

const std::unique_ptr<IDatabase> EmbeddedDB::loadDB(std::string& db_name) {
    return EmbeddedDB::ImplDB::loadDB(db_name);
}