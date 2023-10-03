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
ll d[101][10];
int di = 1'000'000'000;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	fill(d[1], d[1] + 11, 1);
	d[1][0] = 0;
	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j < 10; j++) {
			if (j != 0 && j != 9) d[i][j] = (d[i - 1][j - 1] + d[i - 1][j + 1]) %di;
			else if (j == 0) d[i][0] = (d[i - 1][1]) %di;
			else d[i][9] = (d[i - 1][8]) %di;
		}
	}
	ll ans = 0;
	for (int i = 0; i < 10; i++)
	{
		ans += d[n][i];
	}
	ans = ans % di;
	cout << ans;
}
