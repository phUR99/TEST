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
int map[505][505];
int d[505][505];
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };
int m, n;
int dfs(int x, int y) {
	if (x == m - 1 && y == n - 1) return 1;
	if (d[x][y] != -1) return d[x][y];
	d[x][y] = 0;
	for (int iter = 0; iter < 4; iter++)
	{
		int nx = x + dx[iter];
		int ny = y + dy[iter];
		if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
		if (map[nx][ny] >= map[x][y]) continue;
		d[x][y] += dfs(nx, ny);
	}
	return d[x][y];
}


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);


	cin >> m >> n;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			d[i][j] = -1;
		}
	}
	cout << dfs(0, 0);
	
	
}
