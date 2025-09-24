#include <iostream>
#include <string>

class VigenèreCipher {  
public:
    std::string key;
    std::string alphabet;
    VigenèreCipher() {};

    std::string encode(std::string str) {
        std::string result;
        size_t key_it = 0;
        for (const auto ch : str) {
            size_t is_abc = alphabet.find(ch);
            if (is_abc != std::string::npos) {
                size_t key_num = alphabet.find(key[key_it]);
                result += alphabet[(is_abc + key_num) % alphabet.length()];
            } else {
                result += ch;
            }
            ++key_it;
            if (key_it == key.length()) key_it = 0;
        }
        return result;
    }
    std::string decode(std::string str) {
        std::string result;
        size_t key_it = 0;
        for (const auto ch : str) {
            size_t is_abc = alphabet.find(ch);
            if (is_abc != std::string::npos) {
                size_t key_num = alphabet.find(key[key_it]);
                result += alphabet[(is_abc - key_num + alphabet.length()) % alphabet.length()];
            } else {
                result += ch;
            }
            ++key_it;
            if (key_it == key.length()) key_it = 0;
        }
        return result;
    }
};

int main() {
    VigenèreCipher c;
    c.alphabet = "abcdefghijklmnopqrstuvwxyz";
    c.key = "password";

    std::cout << c.encode("it's a shift cipher!") << std::endl;
    std::cout << c.encode("codewars") << std::endl;
    std::cout << c.encode("waffles") << std::endl;
    std::cout << "==============\n";
    std::cout << c.decode("xt'k s ovzii cahdsi!") << std::endl;
    std::cout << c.decode("rovwsoiv") << std::endl;
    std::cout << c.decode("laxxhsj") << std::endl;

    return 0;
}
