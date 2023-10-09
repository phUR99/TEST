#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <math.h>
#include <tuple>
#include <numeric>

using namespace std;
#define ll long long
int map[105][105];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
 

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k, l;
	cin >> n >> k;
	while (k--)
	{
		int a, b;
		cin >> a >> b;
		map[a][b] = 1;
	}
	cin >> l;
	queue<pair<int, char>> act;
	while (l--)
	{
		int a; char b;
		cin >> a >> b;
		act.push({ a, b });
	}
	deque<pair<int, int>> snake;
	snake.push_back({ 1, 1 });
	map[1][1] = -1;
	int ans = 0;
	int d = 0;
	while (true)
	{
		int nx = snake.back().first + dx[d];
		int ny = snake.back().second + dy[d];
		if (nx <= 0 || nx > n || ny <= 0 || ny > n) { 
			break; 
		}
		if (map[nx][ny] == -1) break;
		ans++;
		if (map[nx][ny] == 0) {
			int ex = snake.front().first;
			int ey = snake.front().second;
			map[ex][ey] = 0;
			snake.pop_front();
		}
		map[nx][ny] = -1;
		snake.push_back({ nx, ny });
		if (!act.empty() && ans == act.front().first)
		{
			char a = act.front().second; act.pop();
			if (a == 'L') d = (3 + d) % 4;
			else d = (d + 1) % 4;
		}
	}
	cout << ans +1;
}