set(APP_SOURCE_FILES
    main.cpp
    options.cpp
)

add_executable(${PROJECT_NAME} ${APP_SOURCE_FILES})
target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/DatabaseCLI/inc)
target_link_libraries(${PROJECT_NAME} PRIVATE CLI11::CLI11 nlohmann_json::nlohmann_json DatabaseLib)
set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/apps)