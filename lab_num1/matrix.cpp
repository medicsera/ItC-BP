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
    for (int row = 0; row < rows_; ++row){
        for (int col = 0; col < cols_; ++col){
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

int Matrix_opp::get_rows() const {return rows_;}

int Matrix_opp::get_cols() const {return cols_;}

// operations

Matrix_opp Matrix_opp::Minor(int del_rows, int del_cols) {
    if (del_rows < 0 || del_rows >= rows_ || del_cols < 0 || del_cols >= cols_){
        throw std::out_of_range("Matrix size out of range");
    }
    Matrix_opp minor(rows_ - 1, cols_ -1);
    int new_row = 0;
    for (int row = 0; row < rows_; ++row){
        if (row != del_rows){
            int new_col = 0;
            for (int col = 0; col < cols_; ++col){
                if (col != del_cols){
                    minor.matrix_[new_row][new_col] = matrix_[row][col];
                    ++new_col;
                }
            }
            ++new_row;
        }
    }
    return minor;
}

bool Matrix_opp::EqMatrix(const Matrix_opp &other) {
    if (rows_ != other.get_rows() || cols_ != other.get_cols()){
        return false;
    }
    for (int row = 0; row < rows_; row++){
        for (int col = 0; col < cols_; col++){
            if (matrix_[row][col] != other.matrix_[row][col]){
                return false;
            }
        }
    }
    return true;
}

void Matrix_opp::SumMatrix(const Matrix_opp &other) {
    if (rows_ != other.rows_ || cols_ != other.cols_){
        throw std::invalid_argument("Different dimensions");
    }
    for (int row = 0; row < rows_; ++row){
        for (int col = 0; col < cols_; ++col){
            matrix_[row][col] += other.matrix_[row][col];
        }
    }
}

void Matrix_opp::SubMatrix(const Matrix_opp &other) {
    if (rows_ != other.rows_ || cols_ != other.cols_){
        throw std::invalid_argument("Different dimensions");
    }
    for (int row = 0; row < rows_; ++row){
        for (int col = 0; col < cols_; ++col){
            matrix_[row][col] -= other.matrix_[row][col];
        }
    }
}

void Matrix_opp::MulNumber(const double num) {
    for (int row = 0; row < rows_; ++row) {
        for (int col = 0; col < cols_; ++col) {
            matrix_[row][col] *= num;
        }
    }
}

void Matrix_opp::MulMatrix(const Matrix_opp &other) {
    if (cols_ != other.rows_){
        std::invalid_argument("Not correct matrix dimensions");
    }
    Matrix_opp mulmatrix(rows_,other.cols_);
    for (int row = 0; row < rows_; ++row) {
        for (int col = 0; col < other.cols_; ++col) {
            double sum = 0;
            for (int i = 0; i < other.rows_; ++i) {
                sum += matrix_[row][i] * other.matrix_[i][col];
            }
            mulmatrix.matrix_[row][col] = sum;
        }
    }
    *this = mulmatrix;
}



