#include <iostream>
#include <vector>

using VVi = std::vector<std::vector<int>>;

std::vector<std::vector<int>> tourney(const std::vector<int>& input) {
    VVi result{input};
    size_t i = 0;

    while(result[i].size() > 1) {
        std::vector<int> cur;

        if (result[i].size() % 2 != 0)
            cur.push_back(*result[i].rbegin());

        for (size_t j = 0; j + 1 < result[i].size(); j += 2) {
            auto num = std::max(result[i][j], result[i][j + 1]);
            cur.push_back(num);
        }

        result.push_back(cur);
        ++i;
    }

    return result;
}



int main() {
    std::vector<int> test1 = { 9, 5, 4, 7, 6, 3, 8, 2 };
    std::vector<int> test2 = { 9, 5, 4, 7, 6, 3, 8 };
    auto result1 = tourney(test1);
    auto result2 = tourney(test2);

    for (const auto& vec : result1) {
        for (const auto& el : vec) {
            std::cout << el << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "=======================\n";

    for (const auto& vec : result2) {
        for (const auto& el : vec) {
            std::cout << el << " ";
        }
        std::cout << std::endl;
    }


    return 0;
}

//                    std::vector<int>{9, 5, 4, 7, 6, 3, 8, 2},
//                    std::vector<int>{9, 7, 6, 8},
//                    std::vector<int>{9, 8},
//                    std::vector<int>{9}

//                    std::vector<int>{9, 5, 4, 7, 6, 3, 8},
//                    std::vector<int>{8, 9, 7, 6},
//                    std::vector<int>{9, 7},
//                    std::vector<int>{9}
