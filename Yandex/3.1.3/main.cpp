#include <iostream>
#include <string>
#include <sstream>
#include <list>

void MakeTrain() {
    std::list<int> train;
    std::string line;

    while (std::getline(std::cin, line)) {
        std::istringstream iss(line);
        std::string command;
        int num;    
        iss >> command >> num;

        if (command == "+left") {
            train.emplace_front(num);
        } else if (command == "+right") {
            train.emplace_back(num);
        } else if (command == "-left") {
            auto it = std::next(train.begin(), std::min<size_t>(num, train.size()));
            train.erase(train.begin(), it);
        } else if (command == "-right") {
            auto it = std::prev(train.end(), std::min<size_t>(num, train.size()));
            train.erase(it, train.end());
        }
    }

    for (const auto& wagon : train) {
        std::cout << wagon << " ";
    }
    std::cout << std::endl;
}