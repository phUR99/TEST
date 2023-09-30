#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <math.h>
#include <tuple>

#define X first
#define Y second
int map[1000][1000];
int dist[1000][1000];
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	queue<pair<int, int>> q;

	for (int i = 0; i < n; i++)
	{
		fill(dist[i], dist[i] + m, -1);
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				q.push({ i, j });
				dist[i][j] = 0;
			}
			if (map[i][j] == 0) dist[i][j] = 0;
		}
	}
	while (!q.empty())
	{
		pair<int, int> cur = q.front(); q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];
			int nz = dist[cur.X][cur.Y] + 1;
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (map[nx][ny] == 0 || dist[nx][ny] >= 0) continue;
			dist[nx][ny] = nz;
			q.push({ nx, ny });

		}

	}
	for (int i = 0; i < n; i++)
	{
		
		for (int j = 0; j < m; j++) {
			cout << dist[i][j] << ' ';
	
		}
		cout << '\n';
	}
}

