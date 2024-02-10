#include <bits/stdc++.h>
using namespace std;
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };
int board[505][505];
bool vis[505][505];


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, num = 0, ans = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++) {
			if (vis[i][j] == false && board[i][j] == 1) {
				num++;
				q.push({ i, j });
				vis[i][j] = true;
				int area = 0;
				while (!q.empty())
				{
					pair<int, int> cur = q.front(); q.pop();
					area++;
					for (int dir = 0; dir < 4; dir++)
					{
						int nx = cur.first + dx[dir];
						int ny = cur.second + dy[dir];
						if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
						if (vis[nx][ny] == true || board[nx][ny] == 0) continue;
						vis[nx][ny] = true;
						q.push({ nx, ny });
					}
				}
				ans = max(ans, area);
			}
		}
	}
	cout << num << '\n' << ans;
}