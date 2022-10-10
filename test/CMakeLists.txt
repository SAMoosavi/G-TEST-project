project(test)

add_executable(G_TEST_run HelperFunctionsTest.cpp)

add_subdirectory(lib/googletest-main)
target_link_libraries(G_TEST_run gtest gtest_main)