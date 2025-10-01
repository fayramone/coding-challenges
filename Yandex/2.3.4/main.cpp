#include <iostream>

int main() {
    int month, year;
    std::cin >> month >> year;
    bool leap;

    if (year % 400 == 0) {
        leap = true;
    } else if (year % 100 == 0) {
        leap = false;
    } else if (year % 4 == 0) {
        leap = true;
    } else {
        leap = false;
    }
    if (month == 2 && leap) {
        std::cout << "29" << std::endl;
    } else if (month == 2 && !leap) {
        std::cout << "28" << std::endl;
    }

    switch(month) {
        case 1:
        case 3:
        case 5: 
        case 7: 
        case 8: 
        case 10:
        case 12:
            std::cout << "31" << std::endl;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            std::cout << "30" << std::endl;
            break;
    }

    return 0;
}
