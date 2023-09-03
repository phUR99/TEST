#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int a[2000001] = {};

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int arr[2][7] = {};
	int n, k;
	cin >> n >> k;
	int s, g;
	int answer = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> s >> g;
		arr[s][g]++;
	}
	for (int i = 0; i < 2; i++)
	{
		for (int j = 1; j < 7; j++) {
			answer += arr[i][j] / k;
			if (arr[i][j] % k != 0) answer++;
		}
	}
	cout << answer;
}