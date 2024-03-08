#include <iostream>
#include <cmath>

bool isint(const float a) {
	int b = a;
	return a == b;
}


int main() {
	int a, b;
	std::cin >> a >> b;


	int min = 0;
	int sum = 0;

	
	for (int i = b; i >= a; i--) {
		if (isint(sqrt(i))) {
			min = i;
			sum += i;

		}
		
	}
	if (min == 0) std::cout << -1;
	else {
		std::cout << sum << std::endl;
		std::cout << min << std::endl;
	}

}