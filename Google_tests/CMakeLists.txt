cmake_minimum_required(VERSION 3.24)
project(Google_tests)

# 'lib' is the folder with Google Test sources
add_subdirectory(googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# 'Google_Tests_run' is the target name
# 'test1.cpp test2.cpp' are source files with tests
add_executable(Google_Tests_run
        TimeTest.cpp
        ../Time.cpp
        ../Activity.cpp
        ../ActivityLog.cpp
        ActivityTest.cpp ActivityLogTest.cpp)

target_link_libraries(Google_Tests_run
        gtest
        gtest_main
        )