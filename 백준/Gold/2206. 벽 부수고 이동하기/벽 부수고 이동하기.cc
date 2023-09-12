#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <tuple>
#define X first
#define Y second
using namespace std;

char map[1001][1001];
int dist[1001][1001][2];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int m, n;
	cin >> m >> n;
	for (int i = 0; i < m; i++)
	{
		string temp;
		cin >> temp;
		for (int j = 0; j < n; j++) {
			map[i][j] = temp[j];
			for (int k = 0; k < 2; k++)
			{
				dist[i][j][k] = -1;
			}

		}
	}
	queue<tuple<int, int, int>> q;
	q.push({ 0, 0, 0 });
	dist[0][0][0] = 1;
	dist[0][0][1] = 1;
	while (!q.empty())
	{
		tuple<int, int, int> cur = q.front(); q.pop();
		for (int iter = 0; iter < 4; iter++)
		{
			int nx = get<0>(cur) + dx[iter];
			int ny = get<1>(cur) + dy[iter];
			int nz = get<2>(cur);
			int nd = dist[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
			if (map[nx][ny] == '1') nz++;
			if (nx < 0 || nx >= m || ny < 0 || ny >= n || nz >= 2) continue;
			if (dist[nx][ny][nz] >= 0) continue;
			
			dist[nx][ny][nz] = nd;
			q.push({ nx, ny, nz });
		}
	}
	if (dist[m - 1][n - 1][0] == -1 && dist[m - 1][n - 1][1] == -1) cout << -1;
	else if (dist[m - 1][n - 1][0] == -1 || dist[m - 1][n - 1][1] == -1) cout << max(dist[m - 1][n - 1][0], dist[m - 1][n - 1][1]);
	else cout << min(dist[m - 1][n - 1][0], dist[m - 1][n - 1][1]);
	return 0;	
}
