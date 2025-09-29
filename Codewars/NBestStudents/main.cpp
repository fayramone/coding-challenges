#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <numeric>

std::vector<std::string> nBestStudents(std::vector<std::string> students, 
        std::vector<std::vector<float>> grades, int n) {
            std::vector<std::string> result;
            result.reserve(static_cast<size_t>(n));
            std::map<float, std::string> hm;

            for (size_t i = 0; i < students.size(); ++i) {
                float sum = std::accumulate(grades[i].begin(), grades[i].end(), 0.0f);
                float avg = sum / grades[i].size();
                hm[avg] = students[i];
            }

            auto it = hm.rbegin();
            for (int i = 0; i < n; ++i) {
                result.push_back(it->second);
                ++it;
            }
            
            return result;
}

int main() {
    std::vector<std::string> vec1 = nBestStudents({"Ben", "Kai"}, {{75, 80}, {77, 89}}, 1);
    std::vector<std::string> vec2 = nBestStudents({"Dave", "Lisa", "Jen"}, 
            {{60, 65, 70}, {71, 88, 76}, {81, 82, 88}}, 2);
    std::vector<std::string> vec3 = nBestStudents({"Katie"}, {{66, 74, 71}}, 1);

    for (const auto& el : vec1) {
        std::cout << el << " ";
    }
    std::cout << std::endl;

    for (const auto& el : vec2) {
        std::cout << el << " ";
    }
    std::cout << std::endl;

    for (const auto& el : vec3) {
        std::cout << el << " ";
    }
    std::cout << std::endl;

    return 0;
}