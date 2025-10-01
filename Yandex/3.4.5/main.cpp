#include <iostream>
#include <queue>
#include <map>
#include <vector>
#include <algorithm>
#include <sstream>

int main() {
    size_t k;
    std::cin >> k;
    std::cin.ignore();

    std::map<std::string, int> freqs;
    std::string line;
    while(std::getline(std::cin, line)) {
        std::istringstream iss(line);
        std::string word;
        while(iss >> word) {
            ++freqs[word];
        }
    }

    std::vector<std::pair<std::string, int>> sortedByFreq(freqs.begin(), freqs.end());
    std::sort(sortedByFreq.begin(), sortedByFreq.end(), 
        [](const auto& p1, const auto& p2){
            if (p1.second != p2.second) {
                return p1.second > p2.second;
            } 
            return p1.first < p2.first;
        }
    );

    for (size_t i = 0; i < std::min(k, sortedByFreq.size()); ++i) {
        std::cout << sortedByFreq[i].first << "\t" << sortedByFreq[i].second << "\n"; 
    }

    return 0;
}