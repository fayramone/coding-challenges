#include <iostream>
#include <string>
#include <list>

int main() {
    std::list<std::string> lines;
    std::string line;
    while (std::getline(std::cin, line)) {
        lines.emplace_back(line);
        if (line == "") break;
    }

    std::string command, clipboard;
    auto cursor = lines.begin();
    while (std::cin >> command) {
        if (command == "Down" && std::next(cursor) != lines.end()) ++cursor;
        else if (command == "Up" && cursor != lines.begin()) --cursor;
        else if (command == "Ctrl+X" && !cursor->empty()) {
            clipboard = *cursor;
            cursor = lines.erase(cursor);
            if (cursor == lines.end() && !lines.empty()) {
                cursor = std::prev(lines.end());
            }
        } else if (command == "Ctrl+V" && !clipboard.empty()) {
            lines.insert(cursor, clipboard);
        }
    }

    for (const auto& l : lines) {
        std::cout << l << std::endl; 
    }

    return 0;
}
