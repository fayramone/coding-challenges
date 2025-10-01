#include <iostream>
#include <string>
#include <cctype>
#include <unordered_map>

std::string soundex(const std::string& word) {
    if (word.empty() || word.size() > 20) return "0000";

    std::string soundexCode;
    soundexCode += static_cast<char>(std::tolower(static_cast<unsigned char>(word[0])));

    std::unordered_map<char, std::string> codeMap = {
        {'b', "1"}, {'f', "1"}, {'p', "1"}, {'v', "1"},
        {'c', "2"}, {'g', "2"}, {'j', "2"}, {'k', "2"}, {'q', "2"}, {'s', "2"}, {'x', "2"}, {'z', "2"},
        {'d', "3"}, {'t', "3"},
        {'l', "4"},
        {'m', "5"}, {'n', "5"},
        {'r', "6"} 
    };

    std::string skipLetters = "aehiouwiy";
    std::string tempCodes;

    for (size_t i = 1; i < word.size(); ++i) {
        char ch = word[i];

        if (skipLetters.find(ch) != std::string::npos) continue;
        if (codeMap.count(ch)) tempCodes += codeMap[ch];
    }

    std::string filteredCodes;
    char prev = '\0';
    for (auto ch : tempCodes) {
        if (ch != prev) filteredCodes += ch;
        prev = ch;
    }

    filteredCodes.resize(3, '0');
    if (filteredCodes.size() > 3) {
        filteredCodes = filteredCodes.substr(0, 3);
    }

    return soundexCode + filteredCodes;
}  

int main() {
    std::string word;
    std::getline(std::cin, word);
    std::cout << soundex(word) << std::endl;

    return 0;
}