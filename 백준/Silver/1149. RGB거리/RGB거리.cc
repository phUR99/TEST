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

int RGB[1000][3];
int ans[1000][3];
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <=n; i++)
	{
		for (int j = 0; j < 3; j++) {
			cin >> RGB[i][j];
		}
	}
	ans[1][0] = RGB[1][0]; ans[1][1] = RGB[1][1]; ans[1][2] = RGB[1][2];
	for (int i = 2; i <= n; i++)
	{
		ans[i][0] = min(ans[i - 1][1], ans[i - 1][2]) + RGB[i][0];
		ans[i][1] = min(ans[i - 1][2], ans[i - 1][0]) + RGB[i][1];
		ans[i][2] = min(ans[i - 1][0], ans[i - 1][1]) + RGB[i][2];
	}
	cout << min({ ans[n][0], ans[n][1], ans[n][2] });

}
