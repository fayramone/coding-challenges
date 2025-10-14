#include <iostream>
#include <string>
#include <cassert>
#include <utility>
#include <vector>

using V = std::pair<int, int>;
using V2 = std::vector<V>;

unsigned int number(const std::vector<std::pair<int, int>>& busStops){
    int num = 0;
    for (const auto& [in, out] : busStops)
        num += (in - out);
    return static_cast<unsigned int>(num);
}


int main() {
    assert(number(V2{V{10,0},V{3,5},V{5,8}}) == 5);
    assert(number(V2{V{3,0},V{9,1},V{4,10},V{12,2},V{6,1},V{7,10}}) == 17);
    assert(number(V2{V{3,0},V{9,1},V{4,8},V{12,2},V{6,1},V{7,8}}) == 21);
    assert(number(V2{V{0,0}}) == 0);
    assert(number(V2{V{10,0},V{13,0},V{17,40}}) == 0);

    std::cout << "All tests passed\n";


    return 0;
}