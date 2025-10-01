#include <iostream>
#include <vector>
#include <utility>

std::pair<size_t, size_t> MatrixArgMax(const std::vector<std::vector<int>>& matrix) {
    size_t row = 0, col = 0;

    for (size_t i = 0; i < matrix.size(); ++i) {
        for (size_t j = 0; j < matrix[i].size(); j++) {
            if (matrix[i][j] > matrix[row][col]) {
                row = i;
                col = j;
            }
        }
    }

    return {row, col};
}