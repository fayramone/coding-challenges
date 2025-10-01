#include <iostream>
#include <queue>
#include <string>

int main() {
    std::string str;
    int n;
    std::priority_queue<int> pq;

    while(std::cin >> str) {
        if (str == "CLEAR") {
            pq = std::priority_queue<int>();
        } else if (str == "EXTRACT") {
            if (!pq.empty()) {
                std::cout << pq.top() << "\n";
                pq.pop();
            } else {
                std::cout << "CANNOT\n";
            }
        } else if (str == "ADD") {
            std::cin >> n;
            pq.push(n);
        }
    }

    return 0;
}