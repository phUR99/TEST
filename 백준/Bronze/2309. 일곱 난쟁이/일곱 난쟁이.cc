#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tmp;
	int arr[9];
	int sum = 0;
	for (int i = 0; i < 9; i++)
	{
		cin >> tmp;
		sum += tmp;
		arr[i] = tmp;
	}
	sort(arr, arr + 9);
	for (int i = 0; i < 9; i++)
	{
		for (int j = i + 1; j < 9; j++) {
			if (sum - arr[i] - arr[j] == 100) {
				arr[i] = 101;
				arr[j] = 101;
				sort(arr, arr + 9);
				for (int i = 0; i < 7; i++)
				{
					cout << arr[i] << "\n";
				}
				return 0;
			}
		}
	}

}