//
// Created by moosavi on 10/10/22.
//


#include "gtest/gtest.h"
#include "../include/HelperFunctions.h"

template<typename T>
void setValueInMatrix(int row, int col, T **matrix, T value) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            matrix[i][j] = value;
        }
    }
}

TEST(HelperFunctionsCreateMatrixTest, TypeInt) {
    int row = 8, col = 4;
    auto matrix = HelperFunctions::createMatrix<int>(row, col);
    setValueInMatrix(row, col, matrix, 1);
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            EXPECT_EQ(matrix[i][j], 1);
        }
    }
    HelperFunctions::deleteMatrix(row, matrix);
}

TEST(HelperFunctionsCreateMatrixTest, TypeFloat) {
    int row = 8, col = 4;
    auto matrix = HelperFunctions::createMatrix<float>(row, col);
    setValueInMatrix(row, col, matrix, 1.1f);
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            EXPECT_FLOAT_EQ(matrix[i][j], 1.1f);
        }
    }
    HelperFunctions::deleteMatrix(row, matrix);
}

TEST(HelperFunctionsCreateMatrixTest, TypeStr) {
    int row = 8, col = 4;
    auto matrix = HelperFunctions::createMatrix<std::string>(row, col);
    setValueInMatrix(row, col, matrix, std::string("test"));
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            EXPECT_EQ(matrix[i][j], "test");
        }
    }
    HelperFunctions::deleteMatrix(row, matrix);
}

TEST(HelperFunctionsCreateMatrixTest, NegativeSize) {
    EXPECT_ANY_THROW(HelperFunctions::createMatrix<int>(4, -4));
    EXPECT_ANY_THROW(HelperFunctions::createMatrix<int>(-4, 4));
}

TEST(HelperFunctionsCreateMatrixTest, ZeroSize) {
    EXPECT_ANY_THROW(HelperFunctions::createMatrix<int>(0, 4));
    EXPECT_ANY_THROW(HelperFunctions::createMatrix<int>(4, 0));
}

TEST(HelperFunctionsDeleteMatrixTest, DeleteTest) {
    int row = 3, col = 4;
    auto matrix = HelperFunctions::createMatrix<float>(3, 4);
    setValueInMatrix(row, col, matrix, 1.1f);
    HelperFunctions::deleteMatrix(row, matrix);
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            EXPECT_NE(matrix[i][j], 1.1f);
        }
    }
    EXPECT_EQ(matrix, nullptr);
}