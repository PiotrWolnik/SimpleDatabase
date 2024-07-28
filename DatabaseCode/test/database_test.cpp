#include <gtest/gtest.h>
#include "groundUpDB.hpp"
#include <filesystem>

namespace fs = std::filesystem;

TEST(DatabaseTests, createEmptyDatabaseTest) {
    std::string db_name{"test_db"};
    Database db(GroundUpDB::createEmpty(db_name));

    ASSERT_TRUE(fs::is_directory(fs::status(db.getDirectory())));
    const auto& p = fs::directory_iterator(db.getDirectory());
    ASSERT_TRUE(p == fs::end(p));
}

TEST(DatabaseTests, keyValueMethodsTest) {
    std::string db_name{"test_db"};
    Database db(GroundUpDB::createEmpty(db_name));

    std::string key{"12345"};
    std::tuple value{"Some player", 45, GameHeroes::Hero::WIZARD, 200};

    db.setKeyValue(key, value);
    auto value_retrieved = db.getKeyValue(key);

    EXPECT_EQ(value_retrieved._data["users_name"].template get<std::string>(), "Some player");
    EXPECT_EQ(value_retrieved._data["age"].template get<int>(), 45);
    EXPECT_EQ(value_retrieved._data["player_type"].template get<std::string>(), "Wizard");
    EXPECT_EQ(value_retrieved._data["level"].template get<int>(), 200);
}
