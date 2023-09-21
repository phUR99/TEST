#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
#define X first
#define Y second

int dx[6] = { -2, -2, 0, 0 ,2, 2 };
int dy[6] = { -1, 1, -2, 2, -1 ,1 };

int map[205][205];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	queue<pair<int, int>> q;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		fill(map[i], map[i] + n, -1);
	}
	int r1, c1, r2, c2;
	cin >> r1 >> c1 >> r2 >> c2;
	q.push({ r1, c1 });
	map[r1][c1] = 0;
	while (!q.empty())
	{
		pair<int, int> cur = q.front(); q.pop();
		for (int iter = 0; iter < 6; iter++)
		{
			int nx = cur.X + dx[iter];
			int ny = cur.Y + dy[iter];
			int nz = map[cur.X][cur.Y] + 1;
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (map[nx][ny] >= 0) continue;
			if (nx == r2 && ny == c2) {
				cout << nz;
				return 0;
			}
			map[nx][ny] = nz;
			q.push({ nx ,ny });
 		}
	}
	cout << -1;
}
