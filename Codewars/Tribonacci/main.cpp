#include <iostream>
#include <vector>

std::vector<int> tribonacci(std::vector<int> signature, int n) {
    std::vector<int> result;
    if (n <= 0 || signature.size() != 3) return result;

    for (size_t i = 0; i < std::size_t(n); i++) {
        if (i < signature.size()) {
            result.push_back(signature[i]);
        } else {
            result.push_back(result[i - 1] + result[i - 2] + result[i - 3]); 
        }
    }
    
    return result;
}

int main() {

    std::vector<int> signature = { 1, 1, 1 };
    
    std::vector<int> test = tribonacci(signature, 10);
    // for (size_t i = 0; i < test.size(); i++) {
    //     std::cout << test[i] << " ";
    // }

    std::cout << std::endl;

    for (auto num : test) {
        std::cout << num << " ";
    }
    
    


    return 0;
}
