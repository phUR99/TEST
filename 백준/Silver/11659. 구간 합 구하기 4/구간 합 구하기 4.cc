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
int arr[100001];
int ans[100001];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	ans[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		ans[i] = ans[i - 1] + arr[i];
	}
	while (m--)
	{
		int st, ed;
		cin >> st >> ed;
		cout << ans[ed] - ans[st - 1] << '\n';
	}
}
