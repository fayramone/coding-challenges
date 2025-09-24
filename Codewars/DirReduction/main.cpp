#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

class DirReduction
{
public:
    static std::vector<std::string> dirReduc(std::vector<std::string> &arr) {
        const std::unordered_map<std::string, std::string> opposites {
            { "NORTH", "SOUTH" },
            { "SOUTH", "NORTH" },
            { "EAST", "WEST" },
            { "WEST", "EAST" }
        };
        std::stack<std::string> st;
        for (const auto& s : arr) {
            if (!st.empty() && opposites.at(st.top()) == s) {
                st.pop();
            } else {
                st.push(s);
            }
        }

        std::vector<std::string> result;
        while(!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }

        std::reverse(result.begin(), result.end());
        return result;
    };
};

int main() {
    std::vector<std::string> d1 = {"NORTH", "SOUTH", "SOUTH", "EAST", "WEST", "NORTH", "WEST"};
    DirReduction d;
    auto lst = d.dirReduc(d1);

    for (const auto& l : lst) {
        std::cout << l << " ";
    }
    std::cout << std::endl;

    return 0;
}