#include <iostream>
#include <math.h>

bool narcissistic( int value ) {
    int length = 1, temp_value = value, sum = 0;
    while (temp_value /= 10) ++length;

    temp_value = value;

    for (int i = 0; i < length; ++i) {
        sum += static_cast<int>(std::pow((temp_value % 10), length));
        temp_value /= 10;
    }

    return sum == value;
}

int main() {
    std::cout << narcissistic(153) << std::endl;


    return 0;
}
