/* * * * * * * * * * * * *
 *                       *
 *                       *
 * Bruh i'm just flexin  *
 *       ヽ( •_)ᕗ        *
 *                       *
 * * * * * * * * * * * * */ 


#include <iostream>
#include <cassert>
#include <cmath>
#include <vector>

class StepInPrimes {
public:
    static std::pair <long long, long long> step(int g, long long m, long long n) {
        long long limit = (long long)floor(sqrt(n)) + 1;

        std::vector<bool> isPrime(static_cast<size_t>(limit) + 1, 0);

        for (long long i = 2; i * i <= limit; ++i) {
            if (!isPrime[static_cast<size_t>(i)]) {
                for (long long j = i * i; j <= limit; j += i) {
                    isPrime[static_cast<size_t>(j)] = true;
                }
            }
        }

        std::vector<long long> primes;
        for (long long i = 2; i <= limit; ++i) {
            if (!isPrime[static_cast<size_t>(i)]) primes.push_back(i);
        }

        long long len = n - m + 1;
        std::vector<bool> isComp(static_cast<size_t>(len) + 1, false);

        for (auto p : primes) {
            long long first = (m + p - 1) / p * p;
            if (first == p) first += p;

            for (long long i = first; i <= n; i += p) {
                isComp[static_cast<size_t>(i - m)] = true;
            }
        }
        
        std::vector<long long> result;
        for (long long i = 0; i <= n - m; ++i) {
            long long num = m + i;
            if (!isComp[static_cast<size_t>(i)] && num >= 2) {
                result.push_back(num);
            }
        }

        size_t i = 0, j = 1;
        while(j < result.size()) {
            long long diff = result[j] - result[i];
            if (diff == g) return { result[i], result[j] };
            else if (diff < g) ++j;
            else ++i;
        }
        return { 0, 0 };
    };
};

void testequal(std::pair <long long, long long> ans, std::pair <long long, long long> sol) {
    assert(ans == sol);
}
void dotest(int g, long long m, long long n, std::pair <long long, long long> expected) {
    testequal(StepInPrimes::step(g, m, n), expected);
}

int main() {
    dotest(2,100,110, {101, 103});
    dotest(11,30000,100000, {0, 0});
    dotest(2,2,50, {3, 5});
    dotest(4,100,110, {103, 107});
    dotest(6,100,110, {101, 107});
    dotest(8,300,400, {359, 367});
    dotest(10,300,400, {307, 317});
    
    std::cout << "All tests passed.\n";

    return 0;
}
