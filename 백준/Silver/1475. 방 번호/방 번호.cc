#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	int arr[10] = {};
	string str;
	cin >> str;
	for (auto s : str) {
		if (s == '6' || s == '9') {
			if (arr[6] < arr[9]) arr[6]++;
			else arr[9]++;
		}
		else arr[s - '0']++;
	}
	cout << *max_element(arr, arr + 10);
}