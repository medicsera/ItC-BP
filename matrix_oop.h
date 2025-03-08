//
// Created by anton on 08.03.2025.
//

#ifndef UNTITLED_MATRIX_OOP_H
#define UNTITLED_MATRIX_OOP_H

class Matrix_opp{
private:
    int rows_, cols_;
    double** matrix_;

public:
    Matrix_opp();
    Matrix_opp(int rows, int cols);
    Matrix_opp(const Matrix_opp& other);
    Matrix_opp(Matrix_opp&& other);
    ~Matrix_opp();

    bool EqMatrix(const Matrix_opp& other);
    void SumMatrix(const Matrix_opp& other);
    void SubMatrix(const Matrix_opp& other);
    void MulNumber(const double num);
    void MulMatrix(const Matrix_opp& other);
    Matrix_opp Transpose();
    Matrix_opp CalcComplements();
    double Determinant();
    Matrix_opp InverseMatrix();

    Matrix_opp operator+(const Matrix_opp& other);
    Matrix_opp operator-(const Matrix_opp& other);
    Matrix_opp operator*(const double other);
    Matrix_opp operator*(const Matrix_opp& other);
    bool operator==(const Matrix_opp& other);
    Matrix_opp operator=(const Matrix_opp& other);
    Matrix_opp operator+=(const Matrix_opp& other);
    Matrix_opp operator-=(const Matrix_opp& other);
    Matrix_opp operator*=(const double other);
    Matrix_opp operator*=(const Matrix_opp& other);
    double& operator()(int row, int col);

    void ShowMatrix();
};
