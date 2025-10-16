#include <iostream>
#include <vector>
#include <unordered_set>

using VI = std::vector<int>;

std::vector<int> solve(std::vector<int> v){
    std::vector<int> result;
    std::unordered_set<int> us(v.begin(), v.end());

    for (const auto& el : v) {
        std::vector<int> temp;
        std::unordered_set<int> visited;
        auto cur = el;

        while(true) {
            temp.push_back(cur);
            visited.insert(cur);

            if (cur % 3 == 0 && us.count(cur / 3) && !visited.count(cur / 3)) {
                cur /= 3;
            } else if (us.count(cur * 2) && !visited.count(cur * 2)) {
                cur *= 2;
            } else {
                break;
            }
        }

        if (temp.size() == v.size()) {
            result = std::move(temp);
            break;
        }
    }

    return result;
}

void printArr(const std::vector<int>& vec) {
    std::cout << "[ ";
    for (const auto& el : vec) {
        std::cout << el << " ";
    }
    std::cout << "]\n";
}


int main() {
    VI test1{1,3};                          // {3,1}
    VI test2{4,2};                          // {2,4}
    VI test3{12,3,9,4,6,8};                 // {9,3,6,12,4,8}    12 4 8 16
    VI test4{558,744,1488,279,2232,1116};   // {279,558,1116,2232,744,1488}

    printArr(solve(test1));
    printArr(solve(test2));
    printArr(solve(test3));
    printArr(solve(test4));

    return 0;
}