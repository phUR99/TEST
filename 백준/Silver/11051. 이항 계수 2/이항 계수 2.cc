#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <math.h>
#include <tuple>
#include <numeric>
using namespace std;
#define ll long long
ll d[1005][1005];



int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	d[0][0] = 1;
	d[1][0] = 1;
	d[1][1] = 1;
	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (j == 0 || j == i) d[i][j] = 1;
			else d[i][j] = (d[i-1][j] + d[i - 1][j - 1])  %10007;
		}
	}
	cout << d[n][k] % 10007;
}
