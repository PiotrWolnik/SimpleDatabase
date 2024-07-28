FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.15.0
)

FetchContent_MakeAvailable(googletest)

set(SOURCES_TEST_FILES
    database_test.cpp
    json_node_test.cpp
)

enable_testing()

add_executable(${PROJECT_NAME}_Tests ${SOURCES_TEST_FILES})
target_link_libraries(${PROJECT_NAME}_Tests GTest::gtest_main DatabaseLib)
set_target_properties(${PROJECT_NAME}_Tests PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/test)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME}_Tests)
