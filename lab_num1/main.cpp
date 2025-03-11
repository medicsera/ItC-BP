//
// Created by anton on 09.03.2025.
//
#include <iostream>
#include "matrix_oop.h"

int main(){

    Matrix_opp *matrixA = new Matrix_opp(3,3);

    matrixA->operator()(0,0) = 1; matrixA->operator()(0,1) = 4; matrixA->operator()(0,2) = 7;
    matrixA->operator()(1,0) = 2; matrixA->operator()(1,1) = 5; matrixA->operator()(1,2) = 8;
    matrixA->operator()(2,0) = 3; matrixA->operator()(2,1) = 6; matrixA->operator()(2,2) = 9;

    Matrix_opp *matrixB = new Matrix_opp(3,3);
    matrixB->operator()(0,0) = 9; matrixB->operator()(0,1) = 6; matrixB->operator()(0,2) = 3;
    matrixB->operator()(1,0) = 8; matrixB->operator()(1,1) = 5; matrixB->operator()(1,2) = 2;
    matrixB->operator()(2,0) = 7; matrixB->operator()(2,1) = 4; matrixB->operator()(2,2) = 1;

    std::cout << "Matrix A" << std::endl;
    matrixA->ShowMatrix();

    Matrix_opp matrixC = *matrixA + *matrixB;
    std::cout << "Matrix A - Matrix B" << std::endl;
    matrixC.ShowMatrix();

    Matrix_opp matrixD = *matrixA - *matrixB;
    std::cout << "Matrix A + Matrix B" << std::endl;
    matrixD.ShowMatrix();

    Matrix_opp matrixE = *matrixA * (*matrixB);
    std::cout << "MullMatrix A and B" << std::endl;
    matrixE.ShowMatrix();

    Matrix_opp matrixF = *matrixA * 5;
    std::cout << "Matrix A * 5" << std::endl;
    matrixF.ShowMatrix();

    Matrix_opp matrixG = *matrixA ;
    std::cout << "Matrix G = Matrix A" << std::endl;
    matrixG.ShowMatrix();

    matrixG += *matrixB;
    std::cout << "Matrix G += Matrix B" << std::endl;
    matrixG.ShowMatrix();

    matrixG -= *matrixA;
    std::cout << "Matrix G -= Matrix B" << std::endl;
    matrixG.ShowMatrix();

    matrixG *= *matrixA;
    std::cout << "Matrix G *= Matrix B" << std::endl;
    matrixG.ShowMatrix();

    matrixG *= 3;
    std::cout << "Matrix G *= 3" << std::endl;
    matrixG.ShowMatrix();

    matrixG = matrixA->Transpose();
    std::cout << "Matrix G transpose" << std::endl;
    matrixG.ShowMatrix();

    bool GandA = matrixG == *matrixA;
    std::cout << "G == A: " << GandA << std::endl;

    bool GandB = matrixG.EqMatrix(*matrixA);
    std::cout << "G EqMatrix B: " << GandB << std::endl;

    matrixA->SumMatrix(*matrixB);
    std::cout << "A sumMatrix B: " <<std::endl;
    matrixA->ShowMatrix();

    matrixA->SubMatrix(*matrixB);
    std::cout << "A subMatrix B: " <<std::endl;
    matrixA->ShowMatrix();

    matrixA->MulMatrix(*matrixB);
    std::cout << "A MulMatrix B: " <<std::endl;
    matrixA->ShowMatrix();

    matrixA->MulNumber(4);
    std::cout << "A MulNumber 4: " <<std::endl;
    matrixA->ShowMatrix();

    Matrix_opp matrixH = Matrix_opp(3,3);

    matrixH = matrixF.CalcComplements();
    std::cout << "CalComplements F " <<std::endl;
    matrixH.ShowMatrix();

    Matrix_opp *matrixI = new Matrix_opp(2,2);
    matrixI->operator()(0,0) = 2; matrixI->operator()(0,1) = 4;
    matrixI->operator()(1,0) = -4; matrixI->operator()(1,1) = -10;

    double detI = matrixI->Determinant();
    std::cout << "Determinant I " << detI << std::endl;

    Matrix_opp matrixRev = matrixI->InverseMatrix();
    std::cout << "InverseMatrix I " <<std::endl;
    matrixRev.ShowMatrix();

    return 0;

}