//
// Created by anton on 09.03.2025.
//

#include <iostream>
#include "matrix_oop.h"

int main(){

    Matrix_opp matA(3,3);
    matA(0, 0) = 1; matA(0, 1) = 2; matA(0, 2) = 3;
    matA(1, 0) = 4; matA(1, 1) = 5; matA(1, 2) = 6;
    matA(2, 0) = 7; matA(2, 1) = 8; matA(2, 2) = 9;

    Matrix_opp *matrixB = new Matrix_opp(3,3);
    matrixB->operator()(0,0) = 1;
    matrixB->operator()(0,1) = 2;
    matrixB->operator()(0,2) = 3;
    matrixB->operator()(1,0) = 4;
    matrixB->operator()(1,1) = 5;
    matrixB->operator()(1,2) = 6;
    matrixB->operator()(2,0) = 7;
    matrixB->operator()(2,1) = 8;
    matrixB->operator()(2,2) = 9;

    std::cout << "Matrix A" << std::endl;
    matA.ShowMatrix();
    matrixB->ShowMatrix();

    return 0;

}