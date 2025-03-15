//
// Created by anton on 08.03.2025.
//

#ifndef UNTITLED_MATRIX_OOP_H
#define UNTITLED_MATRIX_OOP_H

#include <cmath>


constexpr double EPS = 1e-7;

class Matrix_opp{
private:
    int rows_, cols_;
    double** matrix_;

    void MemoryAllocation();
    void MemoryDealocation();
    Matrix_opp Minor(int rows, int cols);


public:
    Matrix_opp();
    Matrix_opp(int rows, int cols);
    Matrix_opp(const Matrix_opp& other);
    Matrix_opp(Matrix_opp&& other);
    ~Matrix_opp();

    int get_rows() const;
    int get_cols() const;

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
    Matrix_opp operator=(Matrix_opp&& other);

    Matrix_opp operator+=(const Matrix_opp& other);
    Matrix_opp operator-=(const Matrix_opp& other);
    Matrix_opp operator*=(const double other);
    Matrix_opp operator*=(const Matrix_opp& other);
    double& operator()(int rows, int cols);
    double operator()(int rows, int cols) const;

    void ShowMatrix();
};

#endif