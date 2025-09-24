#include <iostream>
#include <vector>

std::vector<std::vector<int>>
matrix_multiplication(const std::vector<std::vector<int>> &a,
                      const std::vector<std::vector<int>> &b, size_t n) {
    std::vector<std::vector<int>> result(n, std::vector<int>(n, 0));

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            for (size_t k = 0; k < n; ++k) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    return result;
}

int main() {
    std::vector<std::vector<int>> a = {
        {1, 2, 3}, {4, 5, 6}, {7, 8, 9}
    };
    std::vector<std::vector<int>> b = {
        {1, 2, 3}, {4, 5, 6}, {7, 8, 9}
    };

    std::vector<std::vector<int>> result = matrix_multiplication(a, b, 3);
    for (size_t i = 0; i < 3; ++i) {
        for (size_t j = 0; j < 3; ++j) {
            std::cout << result[i][j] << " ";
        }
        std::cout << std::endl;
    }





    return 0;
}