#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tmp;
	int arr[5];
	for (int i = 0; i < 5; i++)
	{
		cin >> tmp;
		arr[i] = tmp;
	}
	sort(arr, arr + 5);
	int sum = 0;
	for (auto i : arr)
	{
		sum += i;
	}
	cout << sum / 5 << "\n" << arr[2];
}