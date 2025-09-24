#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    std::string convert(std::string s, int numRows) {
        if (numRows <= 1 || s.size() <= static_cast<size_t>(numRows)) return s;

        std::vector<std::string> rows(static_cast<size_t>(numRows));
        int currentRow = 0;
        bool down = false;

        for (const auto& ch : s) {
            rows[static_cast<size_t>(currentRow)] += ch;
            if (currentRow == 0 || currentRow == numRows - 1) {
                down = !down;
            }
            currentRow += down ? 1 : -1;
        }

        std::string result;
        for (const auto& row : rows) {
            result += row;
        }
        return result;
    }
};


int main() {
    Solution sol;
    std::cout << sol.convert("PAYPALISHIRING", 5) << std::endl;


    return 0;
}

