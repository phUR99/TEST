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
ll d[105][105];
int map[105][105];
int n;
ll dfs(int x, int y) {
	if (x >= n && y >= n) return 0;
	if (x == n - 1 && y == n - 1) return 1;
	if (map[x][y] == 0) return 0;
	if (d[x][y] != -1) return d[x][y];
	return d[x][y] = dfs(x + map[x][y], y) + dfs(x, map[x][y] + y);
}


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		fill(d[i], d[i] + n, -1);
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
		}
	}
	
	cout << dfs(0, 0);
}
