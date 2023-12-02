#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define X first
#define Y second
long long di = 1e9 + 7;

long long d[200005][5];


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < 5; i++)
	{
		d[1][i] = 1;
	}


	for (int i = 2; i <= n; i++)
	{
		d[i][0] = (d[i - 1][1] + d[i - 1][2] + d[i - 1][3] + d[i - 1][4]) %di;
		d[i][1] = (d[i - 1][0] + d[i - 1][3] + d[i - 1][4]) %di;
		d[i][2] = (d[i - 1][0] + d[i - 1][4]) %di;
		d[i][3] = (d[i - 1][0] + d[i - 1][1]) %di;
		d[i][4] = (d[i - 1][0] + d[i - 1][1] + d[i - 1][2]) %di;
	}
	long long ans = 0;
	for (int i = 0; i < 5; i++)
	{
		ans += d[n][i];
		ans %= di;
	}
	cout << ans;
}