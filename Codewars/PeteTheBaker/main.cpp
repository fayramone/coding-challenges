#include <iostream>
#include <unordered_map>
#include <climits>

using Ingredients = std::unordered_map<std::string, int>;

int cakes(const Ingredients& recipe, const Ingredients& available) {
    int result = INT_MAX;

    for (const auto& [ingridient, amount] : recipe) {
        if (auto it = available.find(ingridient); it != available.end()) {
            if (amount > it->second) return 0;
            if ((it->second / amount) < result) result = it->second / amount;
        } else return 0;
    }

    return (result == INT_MAX) ? 0 : result;
}

int main() {
    Ingredients recipe = {
        {"apples",  3}, {"flour",  300}, {"milk",  100}, {"sugar", 150}, {"oil", 100}
    };

    Ingredients available = {
        {"flour", 1200}, {"sugar", 1200}, {"eggs", 5}, {"milk", 200}, {"apples", 50}, {"oil", 2000}
    };

    std::cout << cakes(recipe, available) << std::endl;
    std::cout << cakes({{"flour", 500}, {"sugar", 200}, {"eggs", 1}}, 
                {{"flour", 1200}, {"sugar", 1200}, {"eggs", 5}, {"milk", 200}}) << std::endl;
    std::cout << cakes({{"apples", 3}, {"flour", 300}, {"sugar", 150}, {"milk", 100}, {"oil", 100}}, 
                {{"sugar", 500}, {"flour", 2000}, {"milk", 2000}}) << std::endl;

    return 0;
}