# 'Google_test' is the subproject name
project(Google_tests)
cmake_minimum_required(VERSION 3.22)
# 'lib' is the folder with Google Test sources
add_subdirectory(lib/googletest-main)
include_directories(${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR})
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# 'Google_Tests_run' is the target name
# 'test1.cpp tests2.cpp' are source files with tests
add_executable(Google_Tests_run MatrixTest.cpp HelperFunctionsTest.cpp)
target_link_libraries(Google_Tests_run gtest gtest_main)