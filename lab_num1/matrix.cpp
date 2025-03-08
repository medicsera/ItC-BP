#include <iostream>

#include "matrix_oop.h"

// constructors and destructors

Matrix_opp::Matrix_opp() : rows_(0),cols_(0),matrix_(nullptr) {}

Matrix_opp::Matrix_opp(int rows, int cols) {
    rows_ = rows;
    cols_ = cols;
    if (rows <= 0 || cols <= 0) {
        throw std::out_of_range("Matrix size can't contain values zero or negative");
    }
    MemoryAllocation();
}

Matrix_opp::Matrix_opp(const Matrix_opp &other) {
    rows_ = other.rows_;
    cols_ = other.cols_;
    MemoryAllocation();
    for (int row = 0; row < rows_; row++){
        for(int col = 0; col < cols_; col++){
            matrix_[row][col] = other.matrix_[row][col];
        }
    }
}

Matrix_opp::Matrix_opp(Matrix_opp &&other) : rows_(other.rows_), cols_(other.cols_), matrix_(other.matrix_){
    other.rows_ = 0;
    other.cols_ = 0;
    other.matrix_ = nullptr;
}

Matrix_opp::~Matrix_opp() {
    MemoryDealocation();
}

void Matrix_opp::MemoryAllocation() {
    matrix_ = new double*[rows_]();
    for (int row = 0; row < rows_; row++){
        matrix_[row] = new double[cols_]();
        for (int col = 0; col < cols_; col++){
            matrix_[row][col] = 0;
        }
    }
}

void Matrix_opp::MemoryDealocation() {
    for (int row = 0; row < rows_; row++){
        delete[] matrix_[row];
    }
    delete[] matrix_;
    matrix_ = nullptr;
}





