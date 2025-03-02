#include "json_node.hpp"

UsersData::UsersData(std::string users_name, int age, std::string player_type, int level)
{
    _data["users_name"] = users_name;
    _data["age"] = age;
    if (GameHeroes::CheckIfHeroExists()(player_type))
        _data["player_type"] = player_type;
    else
        throw std::runtime_error("Invalid player type!\n");
    _data["level"] = level;
}

UsersData::UsersData(const json &data_to_retrieve) : _data(data_to_retrieve) {}

UsersData::UsersData(const UsersData &user_info) : _data{user_info._data} {}

UsersData& UsersData::operator=(const UsersData &user_info) {
    if (this == &user_info) return *this;
    _data = user_info._data;

    return *this;
}
