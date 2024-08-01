#pragma once

#include <string>
#include <set>
#include <nlohmann/json.hpp>

using json = nlohmann::ordered_json;

namespace GameHeroes {
    static std::set<std::string> HeroType {
        "Knight",
        "Druid",
        "Hunter",
        "Mage",
        "Wizard",
        "Shaman",
        "Warrior"
    };

    struct CheckIfHeroExists {
        bool operator()(std::string hero_type) {
            if (auto hero_iter = std::find(HeroType.begin(), HeroType.end(), hero_type); hero_iter != HeroType.end())
                return true;
            return false;
        }
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
