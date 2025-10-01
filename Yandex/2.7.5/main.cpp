#include <iostream>
#include <vector>
#include <string>

std::vector<std::vector<int>> Transpose(const std::vector<std::vector<int>>& matrix) {
    size_t rows = matrix.size();
    size_t cols = matrix[0].size();

    std::vector<std::vector<int>> result(cols, std::vector<int>(rows));

    for (size_t i = 0; i < matrix.size(); ++i) {
        for (size_t j = 0; j < matrix[i].size(); ++j) {
            result[j][i] = matrix[i][j];
        }
    }

    return result;
}