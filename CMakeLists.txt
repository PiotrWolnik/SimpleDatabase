cmake_minimum_required(VERSION 3.14)
project(SimpleDB VERSION 1.0)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fprofile-arcs -ftest-coverage")

include(FetchContent)
include(CTest)
FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz)
FetchContent_MakeAvailable(json)

add_subdirectory(DatabaseCode)
add_subdirectory(DatabaseCLI)

set(GCOVR_HTML_FOLDER_CMD
        ${CMAKE_COMMAND} -E make_directory ${CMAKE_BINARY_DIR}/coverage
    )

option(CREATE_REPORT "" OFF)
if(CREATE_REPORT)
    find_program(GCOVR_PATH gcovr)
    if(NOT GCOVR_PATH)
        message(FATAL_ERROR "gcovr not found! Aborting...")
    endif()

    set(GCOVR_EXCLUDES "${PROJECT_SOURCE_DIR}/build")

    add_custom_target(coverage
        COMMAND SimpleDB_Tests
        COMMAND ${GCOVR_HTML_FOLDER_CMD}
        COMMAND ${GCOVR_PATH} --html coverage/coverage.html --html-details -r ${PROJECT_SOURCE_DIR} -e ${GCOVR_EXCLUDES} --object-directory=${PROJECT_BINARY_DIR} --print-summary
        BYPRODUCTS ${CMAKE_BINARY_DIR}/coverage/coverage.html
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
        DEPENDS SimpleDB_Tests DatabaseLib
        COMMENT "Generating coverage report"
    )
endif()


# option(CODE_COVERAGE "Enable coverage reporting" OFF)
# if(CODE_COVERAGE)
#     set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
#     if(CMAKE_COMPILER_IS_GNUCXX)
#         include(CodeCoverage)
#         append_coverage_compiler_flags()
#         setup_target_for_coverage_gcovr_html(
#             NAME coverage
#             EXECUTABLE SimpleDB_Tests
#             DEPENDENCIES SimpleDB_Tests DatabaseLib
#             EXCLUDE "build"
#         )
#     endif()
# endif()