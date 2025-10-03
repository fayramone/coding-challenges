/* * * * * * * * * * * * *
 *                       *
 *                       *
 * Bruh i'm just flexin  *
 *       ヽ( •_)ᕗ        *
 *                       *
 * * * * * * * * * * * * */ 

#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <map>

class Solution {
public:
    const std::map<char, std::vector<char>> buttons = {
        {'2', { 'a', 'b', 'c' }}, 
        {'3', { 'd', 'e', 'f' }}, 
        {'4', { 'g', 'h', 'i' }}, 
        {'5', { 'j', 'k', 'l' }}, 
        {'6', { 'm', 'n', 'o' }}, 
        {'7', { 'p', 'q', 'r', 's' }}, 
        {'8', { 't', 'u', 'v' }}, 
        {'9', { 'w', 'x', 'y', 'z' }}
    };

    std::vector<std::string> letterCombinations(std::string digits) {
        if (digits.empty()) return {};

        std::vector<std::string> result = {""};

        for (const auto& d : digits) {
            std::vector<std::string> temp;
            for (const std::string& prefix : result) {
                for (char c : buttons.at(d)) {
                    temp.push_back(prefix + c);
                }
            }
            result = std::move(temp);
        }
        
        return result;
    }
};


int main() {
    std::vector<std::string> test1 = { "ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf" };
    std::vector<std::string> test2 = { };
    std::vector<std::string> test3 = { "a","b","c" };

    Solution sol;
    std::vector<std::string> actual1 = sol.letterCombinations("23");
    std::vector<std::string> actual2 = sol.letterCombinations("");
    std::vector<std::string> actual3 = sol.letterCombinations("2");

    assert(actual1 == test1);
    assert(actual2 == test2);
    assert(actual3 == test3);
    std::cout << "All test passed\n";

    return 0;
}
