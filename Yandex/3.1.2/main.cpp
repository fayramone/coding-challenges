#include <iostream>
#include <string>
#include <deque>
#include <sstream>
#include <vector>


int main() {
    size_t N;
    std::string student, surname, pos;
    std::deque<std::string> students;

    std::cin >> N;
    std::cin.ignore();

    for (size_t i = 0; i < N; ++i) {
        std::getline(std::cin, student);
        std::istringstream iss(student);
        iss >> surname >> pos;
        if (pos == "top") {
            students.emplace_front(surname);
        } else if (pos == "bottom") {
            students.emplace_back(surname);
        }
    }

    size_t M;
    std::vector<std::string> result;
    std::cin >> M;
    for (size_t i = 0; i < M; ++i) {
        size_t idx;
        std::cin >> idx;
        result.push_back(students[idx - 1]);
    }

    for (const auto& r : result) {
        std::cout << r << std::endl;
    }

    return 0;
}
