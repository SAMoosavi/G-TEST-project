//
// Created by moosavi on 10/10/22.
//

#ifndef G_TEST_MATRIX_HELPERFUNCTIONS_H
#define G_TEST_MATRIX_HELPERFUNCTIONS_H

class HelperFunctions {
public:
    template<typename T>
    static T **createMatrix(int row, int col);

    template<typename T>
    static T **createMatrix(int row, int col, T type);

    template<class T>
    static void deleteMatrix(int row, T **&matrix);

private:
    HelperFunctions() = default;
};

#endif //G_TEST_MATRIX_HELPERFUNCTIONS_H
