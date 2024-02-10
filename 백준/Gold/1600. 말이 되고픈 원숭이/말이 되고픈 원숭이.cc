#include <bits/stdc++.h>
using namespace std;
int dx[] = { 0, 1, 0, -1, -1, -2, -1, -2, 1, 2, 1, 2 };
int dy[] = { 1, 0, -1, 0, 2, 1, -2, -1, 2, -1, -2, 1 };

int board[205][205];
int dist[205][205][32];


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, k;
	cin >> k >> n >> m;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			fill(dist[i][j], dist[i][j] + k+1, -1);
		}
		
	}
	queue<tuple<int ,int ,int>> q;
	q.push({ 0, 0, 0 });
	dist[0][0][0] = 0;
	while (!q.empty())
	{
		auto cur = q.front(); q.pop();
		for (int dir = 0; dir < 12; dir++)
		{
			int nx = get<0>(cur) + dx[dir];
			int ny = get<1>(cur) + dy[dir];
			int nk = (dir > 3) ? get<2>(cur) + 1 : get<2>(cur);
			if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
			if (board[nx][ny] == 1 || nk > k || dist[nx][ny][nk] != -1) continue;
			q.push({ nx, ny ,nk });
			dist[nx][ny][nk] = dist[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;			
		}
	}
	int ans = 1e9;
	for (int i = 0; i <= k; i++)
	{
		if(dist[m-1][n-1][i] != -1) ans = min(ans, dist[m - 1][n - 1][i]);
	}
	if (ans == 1e9) {
		cout << -1;
		return 0;
	}
	cout << ans;
}