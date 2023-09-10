#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#define X first
#define Y second
using namespace std;

char map[101][101];
char visited_1[101][101], visited_2[101][101];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	queue<pair<int, int>> q;
	int cnt_1 = 0, cnt_2=0;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string tmp;
		cin >> tmp;
		for (int j = 0; j < n; j++)
		{
			map[i][j] = tmp[j];
			visited_1[i][j] = false;
			visited_2[i][j] = false;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) {		
			if (visited_1[i][j]) continue;
			visited_1[i][j] = true;
			char c = map[i][j];
			q.push({i, j});
			while (!q.empty())
			{
				pair<int, int> cur = q.front(); q.pop();				
				for (int iter = 0; iter < 4; iter++)
				{
					int nx = cur.X + dx[iter];
					int ny = cur.Y + dy[iter];
					if (nx < 0 || ny < 0 || nx >= n || ny >= n)continue;
					if (map[nx][ny] != c || visited_1[nx][ny]==true) continue;
					visited_1[nx][ny] = true;
					q.push({ nx, ny });

				}
			}
			cnt_1++;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (map[i][j]=='G') map[i][j] = 'R';

		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) {
			if (visited_2[i][j]) continue;
			visited_2[i][j] = true;
			char c = map[i][j];
			q.push({ i, j });
			while (!q.empty())
			{
				pair<int, int> cur = q.front(); q.pop();
				for (int iter = 0; iter < 4; iter++)
				{
					int nx = cur.X + dx[iter];
					int ny = cur.Y + dy[iter];
					if (nx < 0 || ny < 0 || nx >= n || ny >= n)continue;
					if (map[nx][ny] != c || visited_2[nx][ny] == true) continue;
					visited_2[nx][ny] = true;
					q.push({ nx, ny });

				}
			}
			cnt_2++;
		}
	}
	cout << cnt_1 << " " << cnt_2;
	return 0;
	
}
