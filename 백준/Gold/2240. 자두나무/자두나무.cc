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
int arr[1001];
int d[1001][31][3];


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t, w;
	cin >> t >> w;
	arr[0] = 1;
	for (int i = 1; i <= t; i++)
	{
		cin >> arr[i];
	}
	for (int i = 1; i <= t; i++)
	{
		d[i][0][1] = d[i - 1][0][1] + (arr[i] == 1 ? 1 : 0);
		for (int j = 1; j <= w; j++) {
			if (i < j) break;
			if (arr[i] == 1) {
				d[i][j][1] = max(d[i - 1][j - 1][2], d[i - 1][j][1]) + 1;
				d[i][j][2] = max(d[i - 1][j - 1][1], d[i - 1][j][2]);
			}
			else {
				d[i][j][1] = max(d[i - 1][j - 1][2], d[i - 1][j][1]);
				d[i][j][2] = max(d[i - 1][j - 1][1], d[i - 1][j][2]) + 1;
			}
		}
	}
	 int ans = 0;
	 for (int j = 0; j <= w; j++) ans = max({ ans, d[t][j][1], d[t][j][2] });
	 cout << ans;
}
