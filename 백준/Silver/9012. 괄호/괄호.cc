#include <iostream>
#include <vector>

int main() {
	int N;
	int sum = 0;
	std::string strs;
	std::cin >> N;
	std::vector<int> vec = {};
	std::vector < std::string > vec2 = {};
	int carry = 0;

	for (int i = 0; i != N; i++) {
		std::cin >> strs;
		for (auto str : strs) {
			if (str == '(') vec.push_back(1);
			if (str == ')') {
				if (vec.empty()) {
					vec2.push_back("NO");
					carry = 1;
					break;
				}
				else {

					vec.pop_back();
				}
			}
		}	
		
		if (vec.empty()&&carry==0) vec2.push_back("YES");
		if(!vec.empty()&&carry==0)vec2.push_back("NO");
		vec.clear();
		carry = 0;

	}
	for (auto i : vec2) {
		std::cout << i << '\n';
	}

	
}