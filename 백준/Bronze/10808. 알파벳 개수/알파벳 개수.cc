#include <iostream>
#include <string>
using namespace std;

int main(void) {
	int arr[26] = {};
	string str;
	cin >> str;
	for (auto i : str) {
		for (int j = 0; j < 26; j++) {
			if (i == 'a' + j) arr[j]++;
		}
	}
	for (int i = 0; i < 26; i++)
	{
		cout << arr[i] << " ";
	}
}