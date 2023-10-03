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
#define ll long long
int arr[10001];
int ans[10001][3];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	ans[1][1] = arr[1];
	for (int i = 2; i <= n; i++)
	{
		ans[i][0] = max({ ans[i - 1][0], ans[i - 1][1], ans[i - 1][2] });
		ans[i][1] = arr[i] + ans[i - 1][0];
		ans[i][2] = arr[i] + ans[i - 1][1];
	}
	int a = max({ ans[n][0], ans[n][1], ans[n][2] });
	cout << a;
}
