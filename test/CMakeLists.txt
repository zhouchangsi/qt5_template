cmake_minimum_required(VERSION 3.15)
project(algorithm CXX)

find_package(GTest REQUIRED)

file(GLOB_RECURSE SOURCES src/*.cpp)
add_executable(leetcode ${SOURCES})

target_include_directories(leetcode PUBLIC ${GTest_INCLUDE_DIRS})
target_link_libraries(leetcode PUBLIC GTest::GTest GTest::Main)

include(GoogleTest)
gtest_discover_tests(leetcode)