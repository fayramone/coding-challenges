#include <iostream>
#include <cassert>
#include <string>
#include <unordered_map>
#include <cctype>


std::string duplicate_encoder(const std::string& word){
    std::unordered_map<char, int> symbols;
    for (const auto& ch : word) {
        unsigned char uch = static_cast<unsigned char>(ch);
        if (std::isalpha(uch)) {
            ++symbols[static_cast<char>(std::tolower(uch))];
        } else {
            ++symbols[ch];
        }
    }

    std::string result;
    result.reserve(word.size());

    for (const auto& ch : word) {
        unsigned char uch = static_cast<unsigned char>(ch);
        char mapped = std::isalpha(uch)
            ? static_cast<char>(std::tolower(uch))
            : ch;
        result += (symbols[mapped] > 1) ? ')' : '(';
    }

    return result;
}

int main() {
    assert(duplicate_encoder("din") == "(((");
    assert(duplicate_encoder("recede") == "()()()");
    assert(duplicate_encoder("Success") == ")())())");
    assert(duplicate_encoder("CodeWarrior") == "()(((())())");
    assert(duplicate_encoder("Supralapsarian") == ")()))()))))()(");
    assert(duplicate_encoder("(( @") == "))((");
    assert(duplicate_encoder(" ( ( )") == ")))))(");

    std::cout << "All tests passed\n";

    return 0;
}