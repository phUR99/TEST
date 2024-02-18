#include <bits/stdc++.h>
using namespace std;

/*
//1. 시간초과 : 가지치기 필요할듯
//2. bfs + 투 포인터 : 투 포인터를 어떻게저거용할 지에 대한 고민

*/
string board[55];
int h[55][55];
int dx[] = {-1, 0, 1, 0, -1, 1, -1,  1 };
int dy[] = { 0, 1, 0, -1, 1, 1, -1, -1 };
bool isused[55][55];
int k = 0;
int n;
set<int> s;

bool canMove = false;
int low, high;

void bfs(int x, int y, int cnt) {
	queue<pair<int, int>> q;
	if (h[x][y] < low || h[x][y] > high) return;
	q.push({ x, y });
	while (!q.empty())
	{
		auto cur = q.front(); q.pop();
		for (int dir = 0; dir < 8; dir++)
		{
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (isused[nx][ny] == true || h[nx][ny] < low || h[nx][ny] > high) continue;
			if (board[nx][ny] == 'K') cnt++;
			if (cnt == k) {
				canMove = true;
				return;
			}
			q.push({ nx, ny });
			isused[nx][ny] = true;
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	int sx, sy;

	for (int i = 0; i < n; i++)
	{
		cin >> board[i];
	}


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> h[i][j];
			if (board[i][j] == 'K') k++;

			if (board[i][j] == 'P') {
				sx = i;
				sy = j;
			}
			s.insert(h[i][j]);
		}
	}
	int result = 1e9;
	auto l = s.begin(), r = s.begin();


	while (r != s.end()) {
		while (l != s.end()) {
			low = *l; high = *r;
			canMove = false;
			for (int i = 0; i < n; i++)
			{
				fill(isused[i], isused[i] + n, false);
			}
			isused[sx][sy] = true;
			bfs(sx, sy, 0);
			if (canMove ==false) break;
			result = min(result, *r - *l);
			++l;
		}
		++r;
	}
	cout << result;


	return 0;
}
