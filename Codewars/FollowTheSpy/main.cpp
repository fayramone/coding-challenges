#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <unordered_map>
#include <unordered_set>

std::string find_routes (const std::vector<std::pair<std::string, std::string>> &routes) {
    if (routes.empty()) return "";

    std::unordered_map<std::string, std::string> next_city;
    std::unordered_set<std::string> destinations;

    for (const auto& [departure, arrive] : routes) {
        next_city[departure] = arrive;
        destinations.insert(arrive);
    }

    std::string start_city;

    for (const auto& [departure, arrive] : routes) {
        if (destinations.find(departure) == destinations.end()) {
            start_city = departure;
            break;
        }
    }

    std::string result = start_city;
    std::string current = start_city;

    while(next_city.find(current) != next_city.end()) {
        current = next_city[current];
        result += ", " + current;
    }

    return result;
}


int main() {
    std::vector<std::pair<std::string, std::string>>  in1 = {{"MNL", "TAG"}, {"CEB", "TAC"}, 
                                                            {"TAG", "CEB"}, {"TAC", "BOR"}};

    std::vector<std::pair<std::string, std::string>> in2 = {{"Chicago", "Winnipeg"}, {"Halifax", "Montreal"}, 
                                                            {"Montreal", "Toronto"}, {"Toronto", "Chicago"},
                                                            {"Winnipeg", "Seattle"}};

    std::cout << find_routes(in1) << std::endl;
    std::cout << find_routes(in2) << std::endl;

    return 0;
}

