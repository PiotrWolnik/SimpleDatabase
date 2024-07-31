#pragma once

#include <string>
#include <unordered_map>
#include <nlohmann/json.hpp>

using json = nlohmann::ordered_json;

namespace GameHeroes {
    enum class Hero {
        KNIGHT,
        DRUID,
        HUNTER,
        MAGE,
        WIZARD,
        SHAMAN,
        WARRIOR
    };

    static std::unordered_map<std::string, Hero> HeroType {
        {"Knight", Hero::KNIGHT},
        {"Druid", Hero::DRUID},
        {"Hunter", Hero::HUNTER},
        {"Mage", Hero::MAGE},
        {"Wizard", Hero::WIZARD},
        {"Shaman", Hero::SHAMAN},
        {"Warrior", Hero::WARRIOR}
    };
}

struct UsersData {
    UsersData(std::string users_name, int age, std::string, int level);
    UsersData(const json &data_to_retrieve);
    
    UsersData(UsersData const&);
    UsersData& operator=(UsersData const&);

    UsersData(UsersData &&) = delete;
    UsersData& operator=(UsersData &&) = delete;

    ~UsersData() = default;

    json _data;
};
