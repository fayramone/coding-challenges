#include <iostream>

int main() {
    int first_day, total;
    std::cin >> first_day >> total;
    int day_num = 1;
    int current_pos = 1;

    if (first_day <= total && first_day >= 1 && first_day <= 7 && total >= 1 && total <= 99) {

        for (int i = 0; i < total + first_day - 1; i++) {
            if (current_pos < first_day) {
                std::cout << "  ";
            } else {
                if (day_num < 10) {
                    std::cout << " " << day_num;
                } else {
                    std::cout << day_num;
                }
                day_num++;
            }
            if(current_pos % 7 == 0) {
                std::cout << std::endl;
            }
            current_pos++;
        }
    } else {
        return 1;
    }
    std::cout << std::endl;

    return 0;
}