#include <bits/stdc++.h>
using namespace std;

string board[1005];
int dist[1005][1005][12];

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> board[i];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++) {
			fill(dist[i][j], dist[i][j] + k + 1, -1);
		}
	}
	queue<tuple<int, int, int>> q;
	q.push({0, 0, 0});
	dist[0][0][0] = 0;
	while (!q.empty())
	{
		int cx, cy, ck;
		tie(cx, cy, ck) = q.front(); q.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cx + dx[dir];
			int ny = cy + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			int nk = (board[nx][ny] == '1') ? ck + 1 : ck;
			if (nk > k || dist[nx][ny][nk] != -1) continue;
			q.push({ nx, ny, nk });
			dist[nx][ny][nk] = dist[cx][cy][ck] + 1;
		}
	}
	int ans = 1e9;
	for (int i = 0; i <= k; i++)
	{
		if (dist[n - 1][m - 1][i] != -1) ans = min(ans, dist[n - 1][m - 1][i]);
	}
	if(ans ==1e9) {
		cout << -1;
		return 0;
	}
	cout << ans +1;
}