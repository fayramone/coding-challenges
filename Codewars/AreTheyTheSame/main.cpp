#include <algorithm>
#include <iostream>
#include <cassert>
#include <vector>

class Same {
public :
    static bool comp(std::vector<int>&a, std::vector<int>&b) {
        if (a.size() != b.size()) return false;

        for (auto& x : a) x *= x;

        std::sort(a.begin(), a.end());
        std::sort(b.begin(), b.end());

        return a == b;
    }
};


int main() {

    Same same;

    std::vector<int> a = {121, 144, 19, 161, 19, 144, 19, 11};
    std::vector<int> b = {14641, 20736, 361, 25921, 361, 20736, 361, 121};
    assert(same.comp(a, b) == true);
    

    a = {121, 144, 19, 161, 19, 144, 19, 11};
    b = {14641, 20736, 361, 25921, 361, 20736, 362, 121};

    assert(same.comp(a, b) == false);
    
    std::cout << "All tests passed.\n";
        
    return 0;
}
