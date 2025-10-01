#include <iostream>
#include <string>
#include <set>

int main() {
	std::string path;
	std::set<std::string> fs;
	while (std::cin >> path) {
		fs.insert("/");
		for (size_t i = 1; i < path.size(); ++i) {
			if (path[i] == '/') {
				fs.insert(path.substr(0, i + 1));
			}
		}
	}

	for (const auto& dir : fs) {
		std::cout << dir << std::endl;
	}

	return 0;
}