//
// Created by moosavi on 10/10/22.
//

#include "gtest/gtest.h"
#include "../include/Matrix.h"

template<typename T>
void setValueInMatrix(int row, int col, T **matrix, double value) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            matrix[i][j] = value * (i + 1) * (j + 1);
        }
    }
}

template<typename T>
auto Initialization(int row, int col, T value) {
    auto matrix = HelperFunctions::createMatrix<T>(row, col);
    setValueInMatrix(row, col, matrix, value);
    return new Matrix<T>(row, col, matrix);
}


class MatrixTest : public ::testing::Test {
protected:
    void SetUp() override {
        this->mat1 = Initialization(3, 3, 1);
        this->mat2 = Initialization(3, 3, 2);
        this->mat3 = Initialization(3, 4, 3);
        this->mat4 = Initialization(4, 5, 4);
    }

    Matrix<int> *mat1{}, *mat2{}, *mat3{}, *mat4{};
};

TEST_F(MatrixTest, GetValueInMatrix) {
    int row, col;
    auto matrix1 = this->mat1->getMatrix(row, col);
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            ASSERT_EQ(matrix1[i][j], 1 * (i + 1) * (j + 1));
        }
    }
}

TEST_F(MatrixTest, AddFunction) {
    int row, col;
    auto mat1 = *this->mat1;
    auto mat2 = *this->mat2;
    mat1.add(mat2);
    auto matrix1 = mat1.getMatrix(row, col);
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            ASSERT_EQ(matrix1[i][j], 3 * (i + 1) * (j + 1));
        }
    }
}

TEST_F(MatrixTest, AddOperator) {
    int row, col;
    auto mat1 = *this->mat1;
    auto mat2 = *this->mat2;
    auto mat = mat1 + mat2;
    auto matrix = mat.getMatrix(row, col);
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            ASSERT_EQ(matrix[i][j], 3 * (i + 1) * (j + 1));
        }
    }
}

TEST_F(MatrixTest, SizeErrorAdd) {
    EXPECT_THROW(this->mat1->add(*this->mat3), SizeError);
    EXPECT_THROW(this->mat3->add(*this->mat4), SizeError);
}

TEST_F(MatrixTest, SubtractionFanction) {
    int row, col;
    auto mat1 = *this->mat1;
    auto mat2 = *this->mat2;
    mat1.subtraction(mat2);
    auto matrix1 = mat1.getMatrix(row, col);
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            ASSERT_EQ(matrix1[i][j], (-1) * (i + 1) * (j + 1));
        }
    }
}

TEST_F(MatrixTest, SubtractionOperator) {
    int row, col;
    auto mat1 = *this->mat1;
    auto mat2 = *this->mat2;
    auto mat = mat1 - mat2;
    auto matrix = mat.getMatrix(row, col);
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            ASSERT_EQ(matrix[i][j], (-1) * (i + 1) * (j + 1));
        }
    }
}

TEST_F(MatrixTest, SizeErrorSubtraction) {
    EXPECT_THROW(this->mat1->subtraction(*this->mat3), SizeError);
    EXPECT_THROW(this->mat3->subtraction(*this->mat4), SizeError);
}

TEST_F(MatrixTest, MultipliedFanction) {
    int row, col;
    auto mat3 = *this->mat3;
    auto mat4 = *this->mat4;
    mat3.multiplied(mat4);
    auto matrix = mat3.getMatrix(row, col);
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
//            TODO: check value
            std::cout << matrix[i][j] << ":" << matrix[i][j] / ((i + 1) * (j + 1)) << " ";
//            ASSERT_EQ(matrix[i][j], (-1) * (i + 1) * (j + 1));
        }
        std::cout << std::endl;
    }
}

TEST_F(MatrixTest, MultipliedOperator) {
    int row, col;
    auto mat1 = *this->mat1;
    auto mat2 = *this->mat2;
    auto mat = mat1 * mat2;
    auto matrix = mat.getMatrix(row, col);
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
//            TODO: check value
//            ASSERT_EQ(matrix[i][j], (-1) * (i + 1) * (j + 1));
        }
    }
}

TEST_F(MatrixTest, SizeErrorMultiplied) {
    EXPECT_THROW(this->mat1->subtraction(*this->mat4), SizeError);
    EXPECT_THROW(this->mat4->subtraction(*this->mat3), SizeError);
}