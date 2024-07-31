#include <gtest/gtest.h>
#include "json_node.hpp"

TEST(UsersDataTest, constructorTest) {
    UsersData users_data{"Kangaroo", 40, "Wizard", 10};

    EXPECT_EQ(users_data._data["users_name"].template get<std::string>(), "Kangaroo");
    EXPECT_EQ(users_data._data["age"].template get<int>(), 40);
    EXPECT_EQ(users_data._data["player_type"].template get<std::string>(), "Wizard");
    EXPECT_EQ(users_data._data["level"].template get<int>(), 10);
}

TEST(UsersData, jsonConstructorTest) {
    json test_ex =
        {
            {"users_name", "Unknown"},
            {"age", 1000},
            {"player_type", "Mage"},
            {"level", 1000}
        };

    UsersData user_data{test_ex};

    EXPECT_EQ(user_data._data["users_name"].template get<std::string>(), "Unknown");
    EXPECT_EQ(user_data._data["age"].template get<int>(), 1000);
    EXPECT_EQ(user_data._data["player_type"].template get<std::string>(), "Mage");
    EXPECT_EQ(user_data._data["level"].template get<int>(), 1000);
}

TEST(UsersDataTest, copyConstructorTest) {
    UsersData users_data{UsersData{"Dragon", 30, "Warrior", 25}};

    EXPECT_EQ(users_data._data["users_name"].template get<std::string>(), "Dragon");
    EXPECT_EQ(users_data._data["age"].template get<int>(), 30);
    EXPECT_EQ(users_data._data["player_type"].template get<std::string>(), "Warrior");
    EXPECT_EQ(users_data._data["level"].template get<int>(), 25);
}

TEST(UsersDataTest, copyAssignementOperatorTest) {
    UsersData users_data_one{"DJ", 20, "Shaman", 100};
    UsersData users_data_two{"Kangaroo", 40, "Wizard", 10};
    users_data_two = users_data_one;

    EXPECT_EQ(users_data_two._data["users_name"].template get<std::string>(), "DJ");
    EXPECT_EQ(users_data_two._data["age"].template get<int>(), 20);
    EXPECT_EQ(users_data_two._data["player_type"].template get<std::string>(), "Shaman");
    EXPECT_EQ(users_data_two._data["level"].template get<int>(), 100);
}