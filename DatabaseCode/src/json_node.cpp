#include "json_node.hpp"

UsersData::UsersData(std::string users_name, int age, GameHeroes::Hero player_type, int level)
{
    _data["users_name"] = users_name;
    _data["age"] = age;
    _data["player_type"] = GameHeroes::HeroType[player_type];
    _data["level"] = level;
}

UsersData::UsersData(const json &data_to_retrieve) : _data(data_to_retrieve) {}

UsersData::UsersData(const UsersData &user_info) : _data{user_info._data} {}

UsersData& UsersData::operator=(const UsersData &user_info) {
    if (this == &user_info) return *this;
    _data = user_info._data;

    return *this;
}
