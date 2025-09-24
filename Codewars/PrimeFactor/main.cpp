#include <iostream>
#include <map>

class PrimeDecomp
{
public:
    static std::string factors(int lst) {
        std::map<int, int> prime_numbers;
        int count = 2;
        std::string result;
        for (; lst != 1; ) {
            while (lst % count == 0) {
                ++prime_numbers[count];
                lst /= count;
            }
            ++count;
        }
        
        for (const auto& [prime, pow] : prime_numbers) {
            result += ("(" + std::to_string(prime));
            if (pow > 1) result += ("**" + std::to_string(pow));
            result += ")";
        }

        return result;
    };
};


int main() {
    PrimeDecomp pd;
    std::cout << pd.factors(86240) << std::endl;

    return 0;
}