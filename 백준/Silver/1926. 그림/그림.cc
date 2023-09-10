#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#define X first
#define Y second
using namespace std;

bool map[501][501];
bool visited[501][501] = { false };
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int BFS(pair<int, int> coordinate, int n, int m) {
	int cnt = 1;
	queue<pair<int, int>> Q;
	visited[coordinate.X][coordinate.Y] = 1;
	Q.push(coordinate);
	while (!Q.empty())
	{
		pair<int, int> current = Q.front(); Q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = dx[dir] + current.X;
			int ny = dy[dir] + current.Y;
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (visited[nx][ny]==true || map[nx][ny] != 1) continue;
			visited[nx][ny] = 1;
			Q.push({ nx, ny });
			cnt++;
		}
	}
	return cnt;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++) {
			int tmp;
			cin >> tmp;
			map[i][j] = tmp;
		}
	}
	int ans = 0, cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0 || visited[i][j] == true) continue;
			int tmp = BFS({ i, j }, n, m);
			if (tmp != 0) cnt++;
			if(ans < tmp) ans = tmp;
		}
	}
	cout << cnt << '\n' << ans;
}
