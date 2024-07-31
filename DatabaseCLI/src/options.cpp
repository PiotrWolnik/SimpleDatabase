#include "options.hpp"

CustomParsers::KeyValueParserValidator::KeyValueParserValidator(std::string& input, std::pair<std::string, std::tuple<std::string, int, std::string, int>>& key_val) {
    name_ = "KEY-VAL-PARSER";
    func_ = [&](std::string& input) -> std::string {
        std::regex pattern(R"((\S+):(\S+),(\d+),(\S+),(\d+))");
        std::smatch match;

        if (std::regex_match(input, match, pattern) && match.size() == 6) {
            key_val.first = match[1].str();
            key_val.second = std::make_tuple(match[2].str(), std::stoi(match[3].str()), match[4].str(), std::stoi(match[5].str()));
            return {};
        }

        return std::string("key_val format: key:str1 val2 str3 val4");
    };
}