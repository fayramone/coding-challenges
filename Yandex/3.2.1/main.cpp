#include <iostream>
#include <unordered_set>

int main() {
	std::unordered_set<int> nums;
	int num;

	while (std::cin >> num) {
		if (nums.count(num)) {
			std::cout << "YES" << std::endl;
		}
		else {
			std::cout << "NO" << std::endl;
			nums.insert(num);
		}
	}

	return 0;
}
