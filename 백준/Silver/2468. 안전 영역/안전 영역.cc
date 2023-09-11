#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#define X first
#define Y second
using namespace std;

int map[101][101];
bool visited[101][101];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int M = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			M = max(M, map[i][j]);
		}
	}
	int ans = 0;
	for (int iter = 0; iter <= M; iter++)
	{
		queue<pair<int, int>> q;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++) {
				visited[i][j] = false;
			}
		}
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++) {
				if (visited[i][j] == true || map[i][j] <= iter) continue;
				q.push({ i, j });
				visited[i][j] = true;
				while (!q.empty())
				{
					pair<int, int> cur = q.front(); q.pop();
					for (int it = 0; it < 4; it++)
					{
						int nx = cur.X + dx[it];
						int ny = cur.Y + dy[it];
						if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
						if (visited[nx][ny] == true || map[nx][ny] <= iter) continue;
						visited[nx][ny] = true;
						q.push({ nx, ny });
					}
				}
				cnt++;
			}
		}
		ans = max(ans, cnt);
	}
	cout << ans;
	return 0;	
}
