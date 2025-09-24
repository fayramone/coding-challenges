#include <iostream>
#include <string>
#include <map>

std::size_t duplicateCount(const std::string& in) {
    std::map<char, size_t> count;
  
    for (size_t i = 0; i < in.length(); i++) {
        count[std::tolower(in[i])]++;
    }
  
    size_t result = 0;
  
    std::map<char, size_t>::iterator it;
    for (it = count.begin(); it != count.end(); it++) {
        if (it->second >= 2) {
            result++;
        }
    }
  
    return result;
}

int main() {
    std::cout << duplicateCount("aabbcde") << std::endl;

    return 0;
}
