cmake_minimum_required(VERSION 3.14)
project(SimpleDB VERSION 1.0)

include(FetchContent)

add_subdirectory(DatabaseCode)
add_subdirectory(DatabaseCLI)