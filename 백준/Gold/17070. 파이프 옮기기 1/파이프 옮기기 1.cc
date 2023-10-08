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
int d[20][20][3];
int a[20][20];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> a[i][j];
		}
	}
	d[1][2][0] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 3; j <= n; j++)
		{
			if (a[i][j] == 0) {
				d[i][j][0] = d[i][j - 1][0] + d[i][j - 1][2];
				d[i][j][1] = d[i - 1][j][1] + d[i - 1][j][2];
				if(a[i-1][j] ==0 && a[i][j-1] ==0) d[i][j][2] = d[i - 1][j - 1][0] + d[i - 1][j - 1][1] + d[i - 1][j - 1][2];
			}
		}
	}
	cout << d[n][n][0] + d[n][n][1] + d[n][n][2];

}