#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#define X first
#define Y second
using namespace std;

char map[1001][1001];
int Jtime[1001][1001];
int Ftime[1001][1001];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	queue<pair<int, int>> jQ, fQ;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++) {
			Ftime[i][j] = -1;
			Jtime[i][j] = -1;
		}
	}
	for (int i = 0; i < n; i++)
	{
		string temp;
		cin >> temp;
		for (int j = 0; j < m; j++) {
			map[i][j] = temp[j];
			if (temp[j] == 'J') {
				jQ.push({ i, j });
				Jtime[i][j] = 0;
			}
			if (temp[j] == 'F') {
				fQ.push({ i, j });
				Ftime[i][j] = 0;
			}
		}
	}
	while (!fQ.empty())
	{
		pair<int, int> cur = fQ.front(); fQ.pop();
		for (int iter = 0; iter < 4; iter++)
		{
			int nx = cur.X + dx[iter];
			int ny = cur.Y + dy[iter];
			int nt = Ftime[cur.X][cur.Y] + 1;
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (Ftime[nx][ny] >= 0 || map[nx][ny] == '#') continue;
			Ftime[nx][ny] = nt;
			fQ.push({ nx, ny });
		}
	}
	while (!jQ.empty())
	{
		pair<int, int> cur = jQ.front(); jQ.pop();
		for (int iter = 0; iter < 4; iter++)
		{
			int nx = cur.X + dx[iter];
			int ny = cur.Y + dy[iter];
			int nt = Jtime[cur.X][cur.Y] + 1;
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
				cout << nt;
				return 0;
			}
			if (Jtime[nx][ny] >= 0 || map[nx][ny] == '#') continue;
			if (Ftime[nx][ny] !=-1 && Ftime[nx][ny] <= nt) continue;
			Jtime[nx][ny] = nt;
			jQ.push({ nx, ny });
		}
	}
	cout << "IMPOSSIBLE";
	return 0;
}
