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

long long int lucasnum(int n) {
    if (n < 0) {
        long long value = lucasnum(-n);
        return ((-n) % 2 == 1) ? -value : value;
    } 
    
    if (n == 0) return 2;
    if (n == 1) return 1;

    long long int a = 2, b = 1;
    for (int i = 2; i <= n; ++i) {
        long long int next = a + b;
        a = b;
        b = next;
    }

    return b;
}

int main() {
    assert(lucasnum(-10) == 123);
    assert(lucasnum(10) == 123);
    assert(lucasnum(-1) == -1);
    assert(lucasnum(5) == 11);
    assert(lucasnum(-5) == -11);
    assert(lucasnum(0) == 2);
    assert(lucasnum(1) == 1);
    std::cout << "All tests passed.\n";

    return 0;
}
