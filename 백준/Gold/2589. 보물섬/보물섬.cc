#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
char map[51][51];
int dist[51][51];
int row, col;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int bfs(int x, int y) {
	int out = 0;
	if (map[x][y] == 'W') return 0;
	for (int i = 0; i < row; i++)
	{
		fill(dist[i], dist[i] + col, -1);
	}
	queue<pair<int, int>> q;
	q.push({ x, y });
	dist[x][y] = 0;
	while (!q.empty()) {
		pair<int, int> cur = q.front(); q.pop();
		for (int iter = 0; iter < 4; iter++)
		{
			int nx = cur.first + dx[iter];
			int ny = cur.second + dy[iter];
			int nd = dist[cur.first][cur.second] + 1;
			if (nx < 0 || nx >= row || ny < 0 || ny >= col) continue;
			if (map[nx][ny] == 'W' || dist[nx][ny] >= 0) continue;
			dist[nx][ny] = nd;
			q.push({ nx, ny });
			out = max(out, nd);
		}
	}

	return out;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int ans = 0;
	cin >> row >> col;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++) {
			int c = bfs(i, j);
			ans= max(ans, c);
		}
	}
	cout << ans;
}
