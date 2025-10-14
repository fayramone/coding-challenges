#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::vector<std::string> friendOrFoe(const std::vector<std::string>& input) {
    std::vector<std::string> result;
    // for (const auto& name : input) {
    //     if (name.size() == 4) result.push_back(name);
    // }
    std::copy_if(input.begin(), input.end(), std::back_inserter(result), [](const std::string& name){
        return (name.size() == 4);
    });
    return result;
}

int main() {
    std::vector<std::string> vec1 = { "Ryan", "Kieran", "Jason", "Yous" };
    std::vector<std::string> vec2 = { "Eminem", "Pete", "Alan", "Jesus", "Homer Simpson" };

    auto result1 = friendOrFoe(vec1);
    auto result2 = friendOrFoe(vec2);

    for (const auto& el : result1) {
        std::cout << el << " ";
    }
    std::cout << std::endl;
    for (const auto& el : result2) {
        std::cout << el << " ";
    }


    return 0;
}
