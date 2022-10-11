cmake_minimum_required(VERSION 3.23)
project(G_TEST_matrix)

set(CMAKE_CXX_STANDARD 14)

set(SOURCES
        src/Matrix.h
        src/MatrixError.h
        src/HelperFunctions.h
        main.cpp
        )

add_executable(G_TEST_matrix ${SOURCES})

target_include_directories(G_TEST_matrix
        PRIVATE
        ${PROJECT_SOURCE_DIR}/include
        )

add_subdirectory(test)