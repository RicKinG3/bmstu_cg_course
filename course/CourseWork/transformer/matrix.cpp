//
// Created by User on 02.06.2023.
//

#include "matrix.h"

Matrix::Matrix(std::initializer_list<std::initializer_list<double>> list) {
    rows = list.size();
    auto it = list.begin();
    cols = it->size();

    matrix.resize(rows);
    for (int i = 0; i < rows; ++i)
        matrix[i].resize(cols);

    int i = 0;
    int j = 0;
    for (const auto &ilist: list) {
        j = 0;
        for (const auto &elem: ilist) {
            matrix[i][j] = elem;
            ++j;
        }
        ++i;
    }
}

std::vector<double> &Matrix::operator[](size_t row) {
    return matrix[row];
}

const std::vector<double> &Matrix::operator[](size_t row) const {
    return matrix[row];
}

Matrix Matrix::operator*(const Matrix &matrix_) {
    Matrix result(rows, matrix_.cols);
    for (size_t i = 0; i < rows; i++)
        for (size_t k = 0; k < matrix_.cols; k++) {
            for (size_t j = 0; j < cols; j++)
                result[i][k] += matrix[i][j] * matrix_[j][k];
        }
    return result;
}