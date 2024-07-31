#pragma once

#include <CLI/CLI.hpp>
#include <iostream>
#include <sstream>
#include <regex>
#include <tuple>
#include <utility>

namespace CustomParsers {
    struct KeyValueParserValidator : public CLI::Validator {
        KeyValueParserValidator(std::string& input, std::pair<std::string, std::tuple<std::string, int, std::string, int>>& key_val);
    };
}
