#include <iostream>
#include <vector>

int main() {
	int N;
	int num = 0;
	int input;
	std::vector<int> vec;
	std::cin >> N;
	for (int i = 0; i != N; i++) {
		std::cin >> input;
		vec.push_back(input);
		
	}
	std::cin >> N;
	for (auto i : vec){
		if (i == N) num++;

		}
	std::cout << num;
	
	
	
}