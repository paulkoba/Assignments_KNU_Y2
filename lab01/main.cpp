#include <iostream>

#include "sparse_matrix.h"

int main() {
    sparse_matrix<std::uint64_t> matrix(3, 2);

    matrix[{0,0}] = 1;
    matrix[{0,1}] = 2;
    matrix[{0,2}] = 3;
    matrix[{1,0}] = 4;
    matrix[{1,1}] = 5;
    matrix[{1,2}] = 6;

    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; ++j) {
            std::cout << matrix[{i, j}] << " ";
        }
        std::cout << "\n";
    }

    matrix = matrix * matrix.transposed();

    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; ++j) {
            std::cout << matrix[{i, j}] << " ";
        }
        std::cout << "\n";
    }

    return 0;
}
