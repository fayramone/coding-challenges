#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

int main() {
	int n, page;
	std::cin >> n;
	std::string word;
	std::map<int, std::vector<std::string>> subject_index;

	for (int i = 0; i < n; ++i) {
		std::cin >> word >> page;
		auto& words = subject_index[page];
		if (std::find(words.begin(), words.end(), word) == words.end()) {
			words.push_back(word);
		}
	}

	for (auto [page_num, words] : subject_index) {
		std::sort(words.begin(), words.end());

		std::cout << page_num;
		for (const auto& w : words) {
			std::cout << " " << w;
		}
		std::cout << std::endl;
	}

	return 0;
}
