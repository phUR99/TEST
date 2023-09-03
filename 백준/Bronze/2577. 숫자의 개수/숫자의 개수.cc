#include <iostream>
#include <string>
using namespace std;
int main() {
	string str = "0123456789";
	long long int product = 1;
	int N;
	for (int i = 0; i < 3; i++)
	{
		cin >> N;

		product *= N;
	}

	string strProduct = to_string(product);
	
	for (auto i : str)
	{
		N = 0;
		for (auto j : strProduct) {
			if (i == j) N++;
		}
		cout << N << '\n';
	}

}