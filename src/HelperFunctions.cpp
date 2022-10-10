//
// Created by moosavi on 10/10/22.
//

#include "../include/HelperFunctions.h"

template<typename T>
T **HelperFunctions::createMatrix(int row, int col) {
    if (row <= 0 || col <= 0)
        throw "size not validation";
    T **matrix = new T *[row];
    for (int i = 0; i < row; ++i) {
        matrix[i] = new T[col];
    }
    return matrix;
}

template<typename T>
T **HelperFunctions::createMatrix(int row, int col, T type) {
    return HelperFunctions::createMatrix<T>(row, col);
}

template<typename T>
void HelperFunctions::deleteMatrix(int row, T **&matrix) {
    for (int i = 0; i < row; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
    matrix = nullptr;
}