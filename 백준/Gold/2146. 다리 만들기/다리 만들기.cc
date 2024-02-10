#include <bits/stdc++.h>
using namespace std;
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };
int board[105][105];
bool vis[105][105];
int dist[105][105];
int ans = 1e9;
int n;


void bfs(int k) {
	for (int i = 0; i < n; i++)
	{
		fill(dist[i], dist[i] + n, -1);
	}
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
		if (board[i][j] == k) {
			q.push({ i, j });
			dist[i][j] = 0;
		}
	while (!q.empty())
	{
		auto cur = q.front(); q.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (board[nx][ny] != 0 && board[nx][ny] != k) {
				ans = min(ans, dist[cur.first][cur.second]);			
				return;
			}
			if (board[nx][ny] != 0 || dist[nx][ny] != -1) continue;			
			q.push({ nx, ny });
			dist[nx][ny] = dist[cur.first][cur.second] + 1;
		}
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int num = 1;	
	cin >> n;
	queue<pair<int, int>> Q;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> board[i][j];
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
		if (board[i][j] != 1 || vis[i][j] == true) continue;
		Q.push({ i, j });
		board[i][j] = num;
		while (!Q.empty())
		{
			auto cur = Q.front(); Q.pop();						
			for (int dir = 0; dir < 4; dir++)
			{
				int nx = cur.first + dx[dir];
				int ny = cur.second + dy[dir];
				if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
				if (board[nx][ny] == 0 || vis[nx][ny] == true) continue;
				Q.push({ nx, ny });
				vis[nx][ny] = true;
				board[nx][ny] = num;
			}
		}
		num++;
	}
	for (int k = 1; k < num; k++)
	{
		bfs(k);

	}
	cout << ans;

}