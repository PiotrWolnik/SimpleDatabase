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

    static std::unordered_map<Hero, std::string> HeroType {
        {Hero::KNIGHT, "Knight"},
        {Hero::DRUID, "Druid"},
        {Hero::HUNTER, "Hunter"},
        {Hero::MAGE, "Mage"},
        {Hero::WIZARD, "Wizard"},
        {Hero::SHAMAN, "Shaman"},
        {Hero::WARRIOR, "Warrior"}
    };
}

struct UsersData {
    UsersData(std::string users_name, int age, GameHeroes::Hero player_type, int level);
    UsersData(const json &data_to_retrieve);
    
    UsersData(UsersData const&);
    UsersData& operator=(UsersData const&);

    UsersData(UsersData &&) = delete;
    UsersData& operator=(UsersData &&) = delete;

    ~UsersData() = default;

    json _data;
};
