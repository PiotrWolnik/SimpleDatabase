#pragma once

#include "database.hpp"
namespace EmbeddedDatabase {
    using namespace Database;

    class EmbeddedDB : public IDatabase {
    public:
        EmbeddedDB(std::string& db_name, std::string& fullpath);
        
        std::string getDirectory() override;

        void setKeyValue(std::string key, std::tuple<std::string, int, std::string, int> user_info) override;  
        UsersData getKeyValue(std::string key) override;

        void destroy() override;
        
        static const std::unique_ptr<IDatabase> createEmpty(std::string& db_name);
        static const std::unique_ptr<IDatabase> loadDB(std::string& db_name);

        ~EmbeddedDB() = default;
    private:
        class ImplDB;
        std::unique_ptr<ImplDB> _impl_db;
    };
};  