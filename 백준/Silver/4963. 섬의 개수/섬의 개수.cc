#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <math.h>
#include <tuple>
using namespace std;
int map[50][50];
bool visited[50][50];
int dx[] = { -1, 0, 1, 0, 1, -1, 1, -1 };
int dy[] = { 0, -1, 0, 1, 1, -1, -1, 1  };


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	while (true)
	{
		int r, c, cnt=0;
		queue<pair<int, int>> q;
		cin >> c >> r;
		if (c == 0 && r == 0) break;
		for (int i = 0; i < r; i++)
		{
			fill(visited[i], visited[i] + c, false);
			for (int j = 0; j < c; j++) {
				cin >> map[i][j];
			}
		}
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++) {

				if (map[i][j] != 1 || visited[i][j] == true) continue;
				q.push({ i, j });
				visited[i][j] = true;
				while (!q.empty())
				{
					pair<int, int> cur = q.front(); q.pop();
					for (int iter = 0; iter < 8; iter++)
					{
						int nx = cur.first + dx[iter];
						int ny = cur.second + dy[iter];
						if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
						if (map[nx][ny] == 0 || visited[nx][ny] == true) continue;
						visited[nx][ny] = true;
						q.push({ nx, ny });
					}
				}
				cnt++;
			}
		}
		cout << cnt << '\n';
		

	}
}

