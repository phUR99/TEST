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

int stair[305];
int ans[305][3];
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> stair[i];
	}
	if (n == 1) {
		cout << stair[1];
		return 0;
	}
	ans[1][1] = stair[1]; ans[2][2] = stair[1] + stair[2]; ans[2][1] = stair[2];
	for (int i = 3; i <= n; i++)
	{
		for (int j = 1; j <=2 ; j++)
		{
			if (j == 1) ans[i][j] = stair[i] + max(ans[i - 2][2], ans[i - 2][1]);
			if (j == 2) ans[i][j] = stair[i] + ans[i - 1][1];
		}
	}
	int a = max(ans[n][1], ans[n][2]);
	cout << a;

}
