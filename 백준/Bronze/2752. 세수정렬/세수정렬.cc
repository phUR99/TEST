#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tmp;
	int arr[3];
	for (int i = 0; i < 3; i++) {
		cin >> tmp;
		arr[i] = tmp;
	}
	sort(arr, arr + 3);
	for (int i = 0; i < 3; i++)
	{
		cout << arr[i] << "\n";
	}
}