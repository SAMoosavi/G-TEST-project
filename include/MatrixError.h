//
// Created by moosavi on 10/10/22.
//

#ifndef G_TEST_MATRIX_MATRIXERROR_H
#define G_TEST_MATRIX_MATRIXERROR_H

#include <string>

using std::string;

class MatrixError : public std::exception {
public:
    string getError() {
        return errorMsg;
    }

protected:
    string errorMsg;
};

class SizeError : public MatrixError {
private:
    string errorMsg = "not correct size";
};

#endif //G_TEST_MATRIX_MATRIXERROR_H
