//
// Created by moosavi on 10/10/22.
//

#ifndef G_TEST_MATRIX_MATRIX_H
#define G_TEST_MATRIX_MATRIX_H


#include "HelperFunctions.h"
#include "MatrixError.h"


template<typename T>
class Matrix {
public:
    Matrix(int row, int col, T **matrix) { this->setMatrix(row, col, matrix); };

    Matrix(const Matrix<T> &mat) { this->setMatrix(mat._row, mat._col, mat._matrix); };

    ~Matrix() { HelperFunctions::deleteMatrix(this->_row, this->_matrix); }

    Matrix<T> &operator=(const Matrix<T> &mat) {
        HelperFunctions::deleteMatrix(this->_row, this->_matrix);
        this->setMatrix(mat._row, mat._col, mat._matrix);
        return *this;
    };

    void setMatrix(int row, int col, T **matrix);

    T **getMatrix(int &row, int &col);

    Matrix<T> operator+(const Matrix<T> &mat);

    void add(const Matrix<T> &mat);

    Matrix<T> operator-(const Matrix<T> &mat);

    void subtraction(const Matrix<T> &mat);

    Matrix<T> operator*(const Matrix<T> &mat);

    void multiplied(const Matrix<T> &mat);

    bool operator==(const Matrix<T> &mat) { return this->equal(mat); }

    bool equal(const Matrix<T> &mat);

private:
    int _row{}, _col{};
    T **_matrix;

    bool addValidation(const Matrix<T> &mat);

    T **adder(const Matrix<T> &mat);

    bool subtractionValidation(const Matrix<T> &mat);

    T **subtractioner(const Matrix<T> &mat);

    T **multiplier(const Matrix<T> &mat);

    bool multipliedValidation(const Matrix<T> &mat);
};


#endif //G_TEST_MATRIX_MATRIX_H
