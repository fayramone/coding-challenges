#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

int main() {
	int m, n;
	std::string word, ngram;
	std::vector<std::string> words;
	std::map<std::string, int> n_grams;
	
	std::cin >> m >> n;
	for (int i = 0; i < m; ++i) {
		std::cin >> word;
		words.push_back(word);
	}

	for (const auto& w : words) {
		if (static_cast<int>(w.size()) < n) {
			continue;
		}
		for (size_t i = 0; i < w.size() - n + 1; ++i) {
			ngram = w.substr(i, n);
			++n_grams[ngram];
		}
	}

	std::vector<std::pair<std::string, int>> sorted_ngrams(n_grams.begin(), n_grams.end());

	std::sort(sorted_ngrams.begin(), sorted_ngrams.end(), 
		[](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
			if (a.second != b.second) return a.second > b.second;
			return a.first < b.first;
		});

	for (auto [w, num] : sorted_ngrams) {
		std::cout << w << " - " << num << std::endl;
	}


	return 0;
}
