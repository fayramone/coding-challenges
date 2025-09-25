#include <iostream>
#include <string>
#include <cctype>

std::string alphabet_position(const std::string &text) {
	if (text.empty()) return "";
	std::string result;
	for (const auto& ch : text) {
		if (std::isalpha(ch)) {
			int num = std::tolower(ch) - 'a' + 1;
			result += std::to_string(num) + ' ';
		}
	}
	if (!result.empty()) result.pop_back();
	return result;
}

int main() {
	std::cout << alphabet_position("The sunset sets at twelve o' clock.")
			<< "\n" << alphabet_position("The narwhal bacons at midnight.")
			<< "\n" << alphabet_position("0123456789")
			<< "\n" << alphabet_position(",./<>?-_=+ ")
			<< "\n" << alphabet_position("") << std::endl;


	return 0;
}