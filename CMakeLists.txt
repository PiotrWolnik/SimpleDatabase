cmake_minimum_required(VERSION 3.14)
project(SimpleDB VERSION 1.0)

include(FetchContent)
FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz)
FetchContent_MakeAvailable(json)

add_subdirectory(DatabaseCode)
add_subdirectory(DatabaseCLI)