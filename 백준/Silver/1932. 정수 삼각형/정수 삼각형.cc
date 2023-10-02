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

int arr[501][501];
int ans[501][501];
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	for (int i = 1; i <=n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cin >> arr[i][j];
		}
	}
	ans[1][1] = arr[1][1];
	for (int i = 2; i <=n; i++)
	{
		ans[i][1] = ans[i - 1][1] + arr[i][1];
		ans[i][i] = ans[i - 1][i - 1] + arr[i][i];
		for (int j = 2; j <= i-1; j++)
		{
			ans[i][j] = max(ans[i - 1][j - 1], ans[i - 1][j]) + arr[i][j];
		}
	}
	int a = ans[n][1];
	for (int i = 1; i <=n; i++)
	{
		if (a < ans[n][i]) a = ans[n][i];
	}
	cout << a;
}
