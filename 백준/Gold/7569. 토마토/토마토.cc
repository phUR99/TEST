#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#define X first
#define Y second
using namespace std;

int map[101][101][100];
int dist[101][101][101];
int dx[6] = { 1, 0, 0, -1, 0, 0 };
int dy[6] = { 0, 1, 0, 0, -1, 0 };
int dz[6] = { 0, 0, 1, 0, 0, -1 };

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int m, n, h;
	queue<pair<int, pair<int, int>>> q;
	cin >> m >> n >> h;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j <n; j++) {
			for (int k = 0; k < m; k++)
			{
				cin >> map[j][k][i];
				if (map[j][k][i] == 1) {
					q.push({ j, {k, i} });
					dist[j][k][i] = 0;
				}
				else dist[j][k][i] = -1;
			}
		}
	}
	int day = 0;
	while (!q.empty())
	{
		pair<int, pair<int, int>> cur = q.front(); q.pop();
		for (int iter = 0; iter < 6; iter++)
		{
			int nx = cur.X + dx[iter];
			int ny = cur.Y.X + dy[iter];
			int nz = cur.Y.Y + dz[iter];
			int nd = dist[cur.X][cur.Y.X][cur.Y.Y] + 1;
			if (nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h) continue;
			if (dist[nx][ny][nz] >= 0 || map[nx][ny][nz] == -1) continue;
			dist[nx][ny][nz] = nd;
			q.push({ nx, {ny, nz} });
			if (nd > day) day = nd;
		}
	}
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++)
			{
				if (map[j][k][i] == 0) if (dist[j][k][i] == -1) {
					cout << -1;
					return 0;
				}
			}
		}
	}
	cout << day;
	return 0;
	
}
