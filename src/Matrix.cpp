//
// Created by moosavi on 10/10/22.
//

#include "../include/Matrix.h"

template<typename T>
void Matrix<T>::setMatrix(int row, int col, T **matrix) {
    this->_row = row;
    this->_col = col;
    this->_matrix = HelperFunctions::createMatrix<T>(row, col);
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            this->_matrix[i][j] = matrix[i][j];
        }
    }
}

template<typename T>
T **Matrix<T>::adder(const Matrix<T> &mat) {
    auto adderMatrix = HelperFunctions::createMatrix<T>(this->_row, this->_col);
    for (int i = 0; i < this->_row; ++i) {
        for (int j = 0; j < this->_col; ++j) {
            adderMatrix[i][j] = this->_matrix[i][j] + mat._matrix[i][j];
        }
    }
    return adderMatrix;
}

template<typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T> &mat) {
    if (this->addValidation(mat))
        return Matrix<T>(this->_row, this->_col, this->adder(mat));
    else throw SizeError();
}

template<typename T>
void Matrix<T>::add(const Matrix<T> &mat) {
    if (this->addValidation(mat)) {
        HelperFunctions::deleteMatrix<T>(this->_row, this->_matrix);
        this->_matrix = this->adder(mat);
    } else throw SizeError();
}

template<typename T>
bool Matrix<T>::addValidation(const Matrix<T> &mat) {
    return this->_row == mat._row && this->_col == mat._col;
}

template<typename T>
bool Matrix<T>::subtractionValidation(const Matrix<T> &mat) {
    return this->_row == mat._row && this->_col == mat._col;
}

template<typename T>
T **Matrix<T>::subtractioner(const Matrix<T> &mat) {
    auto adderMatrix = HelperFunctions::createMatrix<T>(this->_row, this->_col);
    for (int i = 0; i < this->_row; ++i) {
        for (int j = 0; j < this->_col; ++j) {
            adderMatrix[i][j] = this->_matrix[i][j] - mat._matrix[i][j];
        }
    }
    return adderMatrix;
}

template<typename T>
Matrix<T> Matrix<T>::operator-(const Matrix<T> &mat) {
    if (this->subtractionValidation(mat))
        return Matrix<T>(this->_row, this->_col, this->subtractioner(mat));
    else throw SizeError();
}

template<typename T>
void Matrix<T>::subtraction(const Matrix<T> &mat) {
    if (this->subtractionValidation(mat)) {
        HelperFunctions::deleteMatrix<T>(this->_row, this->_matrix);
        this->_matrix = this->subtractioner(mat);
    } else throw SizeError();
}

template<typename T>
T **Matrix<T>::multiplier(const Matrix<T> &mat) {
    auto multiplierMatrix = HelperFunctions::createMatrix<T>(this->_row, mat._col);
    for (int i = 0; i < this->_row; ++i) {
        for (int j = 0; j < mat._col; ++j) {
            T sum = this->_matrix[i][0] * mat._matrix[0][j];
            for (int k = 1; k < this->_col; ++k) {
                sum += this->_matrix[i][k] * mat._matrix[k][j];
            }
            multiplierMatrix[i][j] = sum;
        }
    }
    return multiplierMatrix;
}

template<typename T>
bool Matrix<T>::multipliedValidation(const Matrix<T> &mat) {
    return this->_col == mat._row;
}

template<typename T>
void Matrix<T>::multiplied(const Matrix<T> &mat) {
    if (this->multipliedValidation(mat)) {
        HelperFunctions::deleteMatrix<T>(this->_row, this->_matrix);
        this->_matrix = this->multiplier(mat);
        this->_col = mat._col;
    } else throw SizeError();
}

template<typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T> &mat) {
    if (this->multipliedValidation(mat)) {
        return Matrix<T>(this->_row, mat._col, this->multiplier(mat));
    } else throw SizeError();
}

template<typename T>
bool Matrix<T>::equal(const Matrix<T> &mat) {
    if (!(this->_row == mat._row && this->_col == mat._col))
        return false;
    for (int i = 0; i < this->_row; ++i) {
        for (int j = 0; j < this->_col; ++j) {
            if (this->_matrix[i][j] != mat._matrix[i][j])
                return false;
        }
    }
    return true;
}

template<typename T>
T **Matrix<T>::getMatrix(int &row, int &col) {
    row = this->_row;
    col = this->_col;
    return this->_matrix;
}
