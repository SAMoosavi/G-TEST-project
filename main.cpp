#include <iostream>
#include "include/HelperFunctions.h"

int main() {
    auto a = HelperFunctions::createMatrix<int>(3, 3); // undefined reference to `T** HelperFunctions::createMatrix<T>(int, int)'
}
