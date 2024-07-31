#include "options.hpp"
#include <nlohmann/json.hpp>
#include "groundUpDB.hpp"

using json = nlohmann::ordered_json;

int main(int argc, char **argv) {
    
    CLI::App app{"SimpleDB"};
    argv = app.ensure_utf8(argv);

    std::string db_name;
    app.add_option("-c,--create", db_name, "Provide a name for your database");
    app.add_option("-n,--name", db_name, "Provide name of the database you want to load");

    bool to_be_destroyed{false};
    app.add_flag("-d,--destroy", to_be_destroyed, "Provide name of the database to destroy");
    
    std::pair<std::string, std::tuple<std::string, int, std::string, int>> key_val_parsed;
    std::string raw_key_val;
    std::string key;
    app.add_option("-s,--set-key-val", raw_key_val, "Provide key for a database")->transform(CLI::Validator(CustomParsers::KeyValueParserValidator(raw_key_val, key_val_parsed)));
    app.add_option("-g,--get-key", key, "Get a key from database");

    CLI11_PARSE(app, argc, argv);

    if (app.count("-c") > 0 || app.count("--create") > 0) {
        Database db(GroundUpDB::createEmpty(db_name));
        std::cout << "Database: " << db_name << " was created!\n";
    }
    
    if (to_be_destroyed) {
        if (app.count("-n") == 0 && app.count("--name") == 0) {
            std::cout << "You must provide name of the database you want to destroy!";
            return EXIT_FAILURE;
        }
        Database db(GroundUpDB::loadDB(db_name));
        db.destroy();
        std::cout << "Database: " << db_name << " was destroyed\n";
    }

    if (app.count("-s") > 0 || app.count("--set-key-val") > 0) {
        if (app.count("-n") == 0 && app.count("--name") == 0) {
            std::cout << "You must provide name of the database to which you want to add key-value!";
            return EXIT_FAILURE;
        }
        Database db(GroundUpDB::loadDB(db_name));

        db.setKeyValue(key_val_parsed.first, key_val_parsed.second);
        std::cout << "Key and value were added to " << db_name << " database!\n";
    }

    if (app.count("-g") > 0 && app.count("--get-key") > 0) {
        if (app.count("-n") == 0 && app.count("--name") == 0) {
            std::cout << "You must provide name of the database from which you want to retrieve key-value!";
            return EXIT_FAILURE;
        }
        Database db(GroundUpDB::loadDB(db_name));
        auto user = db.getKeyValue(key);
        std::cout << user._data << std::endl;
        std::cout << "Operation of retrieving key was successfull!\n";
    }
    
    std::cout << "Thank you, that's it for today!\n";
    return EXIT_SUCCESS;
}