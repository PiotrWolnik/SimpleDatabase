set(SOURCE_FILES
    database.cpp
    groundUpDB.cpp
    json_node.cpp
)

add_library(DatabaseLib STATIC ${SOURCE_FILES})
target_include_directories(DatabaseLib PUBLIC ${PROJECT_SOURCE_DIR}/DatabaseCode/inc)
target_compile_features(DatabaseLib PUBLIC cxx_std_17)
target_link_libraries(DatabaseLib PUBLIC nlohmann_json::nlohmann_json)
set_target_properties(DatabaseLib PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
