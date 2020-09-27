cmake_minimum_required(VERSION 3.2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(FIRST_VAR On CACHE BOOL "description 1" FORCE)
set(SECOND_VAR 23 "description 2")
option(BUILD_COVERAGE "Build coverage" ON)

set(
  HUNTER_CACHE_SERVERS
  "https://github.com/bmstu-iu8-cpp-sem-3/hunter-cache"
  CACHE STRING "Default cache server"
)

include("tools/gate/cmake/HunterGate.cmake")

HunterGate(
#  URL "https://github.com/cpp-pm/hunter/archive/v0.23.218.tar.gz"
#  SHA1 "9a3594a61227967fb92159339ba326701b287b19"
#        URL "https://github.com/cpp-pm/hunter/archive/v0.16.15.tar.gz"
#        SHA1 "6974c2150fc0d3b09de3ad1efcbf15d360647ffa"
        URL "https://github.com/ruslo/hunter/archive/v0.23.214.tar.gz"    # URL к ядру Hunter
        SHA1 "e14bc153a7f16d6a5eeec845fb0283c8fad8c358"
)


# TODO: rename project and delete this comment
project(JSONpa)
string(APPEND CMAKE_CXX_FLAGS " -pedantic -Werror -Wall -Wextra")
string(APPEND CMAKE_CXX_FLAGS " -Wno-unused-command-line-argument")
string(APPEND CMAKE_CXX_FLAGS " -Wshadow -Wnon-virtual-dtor")
string(APPEND CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/GCCFIXGTEST.cmake")

hunter_add_package(GTest)
#hunter_add_package(Boost COMPONENTS filesystem regex)
hunter_add_package(nlohmann_json)
#hunter_add_package(nlohmann-json)

find_package(nlohmann_json CONFIG REQUIRED)
#find_package(nlohmann-json REQUIRED)
find_package(GTest CONFIG REQUIRED)
message (WARNING "Find package 2 looks for packages here: ${CMAKE_MODULE_PATH}")
#find_package(Boost CONFIG REQUIRED filesystem regex)
find_package(Threads REQUIRED)

# TODO: change template word to project name and delete this comment
add_library(JSONpa STATIC
  # enum your files and delete this comment
  ${CMAKE_CURRENT_SOURCE_DIR}/sources/source.cpp
)
add_executable(tests
  # TODO: enum your files and delete this comment
  ${CMAKE_CURRENT_SOURCE_DIR}/tests/test.cpp
)

# TODO: change template word to project name and delete this comment
target_include_directories(JSONpa
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)
target_include_directories(tests 
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)
# TODO: change template word to project name and delete this comment
target_link_libraries(tests
        ${CMAKE_THREAD_LIBS_INIT}
        GTest::main
        GTest::gtest
        nlohmann_json
        JSONpa)

enable_testing()
add_test(NAME unit_tests COMMAND tests) 

if(BUILD_COVERAGE)
  set(ENABLE_COVERAGE ON CACHE BOOL "Enable coverage build." FORCE)
  list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
  find_package(codecov)
  # TODO: change template word to project name and delete this comment
  add_coverage(JSONpa)
  add_coverage(tests)
  list(APPEND LCOV_REMOVE_PATTERNS "'${PROJECT_SOURCE_DIR}/tests/*'")
  coverage_evaluate()
endif()