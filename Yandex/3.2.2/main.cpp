#include <iostream>
#include <set>
#include <algorithm>

int main() {
	std::set<char> letters;
	std::string str;
	bool isFirst = true;

	while (std::cin >> str) {
		std::set<char> current_word_letters;
		for (const auto& ch : str) {
			current_word_letters.insert(ch);
		}
		
		if (isFirst) {
			letters = current_word_letters;
			isFirst = false;
		}
		else {
			std::set<char> temp;
			std::set_intersection(
				letters.begin(), letters.end(), 
				current_word_letters.begin(), current_word_letters.end(),
				std::inserter(temp, temp.begin())
			);
			letters = temp;
		}
	}

	for (const auto& letter : letters) {
		std::cout << letter;
	}

	return 0;
}
