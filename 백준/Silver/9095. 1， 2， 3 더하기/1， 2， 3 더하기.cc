#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <math.h>
#include <tuple>
using namespace std;

int arr[1'000'001];
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	arr[1] = 1, arr[2] = 2, arr[3] = 4;
	for (int i = 4; i <= 12; i++)
	{
		arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
	}

	while (t--)
	{
		int n;
		cin >> n;

		cout << arr[n] << '\n';
	}
}
