//
// Created by User on 02.06.2023.
//

#ifndef LAB_03_MATRIX_H
#define LAB_03_MATRIX_H

#include <vector>
#include <iostream>

class Matrix {
public:
    Matrix(int n, int m) : rows(n), cols(m) {
        matrix.resize(n);
        for (int i = 0; i < n; ++i)
            matrix[i].resize(m);
    };

    Matrix(std::initializer_list<std::initializer_list<double>> list);

    Matrix operator*(const Matrix &secondMatrix);

    std::vector<double> &operator[](size_t row);

    const std::vector<double> &operator[](size_t row) const;

private:
    std::vector<std::vector<double>> matrix;
    int rows;
    int cols;
};


#endif //LAB_03_MATRIX_H
