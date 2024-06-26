#include <bits/stdc++.h>
using namespace std;
/*
#14500
1. 순서 강제 + 가능한 모양 한정 -> 예외처리 필요한 모양 필요 ?
틀린 이유 : dfs로 해결되지 않은 모양 더 있음 -> 에외처리
3 3
1 1 0
1 0 0
1 0 0
3 3
1 1 1
1 0 0
0 0 0
*/
int n, m;
int board[505][505];
bool visited[505][505];

int dx[] = { 0, 1 ,0, -1};
int dy[] = { 1, 0, -1, 0};

int exceptShape[10][4][2]{
	{{0, 0}, {0, 1}, {0, 2}, {-1, 2}},
	{{0, 0}, {1, 0}, {2, 0}, {2, -1}},

	{{0, 0}, {1, 0}, {1, -1}, {2, -1}},
	{{0, 0}, {0, 1}, {-1, 1}, {-1, 2}},

	{{0, 0}, {1, 0}, {1, -1}, {2, 0}},
	{{0, 0}, {0, 1}, {-1, 1}, {0, 2}},
	// ㄱ ㄴ
	{ {0, 0}, {1, 0}, {0, 1}, {0, 2}},
	{ {0, 0}, {0, 1}, {1, 0}, {2, 0}},
	// ㅜ ㅏ
	{ {0, 0}, {0, 1}, {1, 1}, {0, 2}},
	{ {0, 0}, {1, 0}, {1, 1}, {2, 0}}
};

int findExceptSum(int x, int y) {
	int ret = 0;
	for (int shape = 0; shape < 10; shape++)
	{
		int cur = 0;
		for (int nxt = 0; nxt < 4; nxt++)
		{
			int nx = x + exceptShape[shape][nxt][0];
			int ny = y + exceptShape[shape][nxt][1];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
				cur -= 987654321;
				break;
			}
			cur += board[nx][ny];
		}
		ret = max(cur, ret);
	}
	return ret;
}

int findMaxSum(int sx, int sy, int x, int y, int cnt) {
	if (cnt == 4) return 0;

	if (x < 0 || x >= n || y < 0 || y >= m || x < sx || y < sy) return 0;

	if (visited[x][y] == true) return 0;
	visited[x][y] = true;

	int ret = 0;
	for (int dir = 0; dir < 4; dir++)
	{
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		ret = max(ret, findMaxSum(sx, sy, nx, ny, cnt + 1) + board[x][y]);
	}
	visited[x][y] = false;
	return ret;
	
}

int main() {
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
	/////////////////////////////////////////////////////////////////
	
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++) {
			ans = max(ans, findMaxSum(i, j, i, j, 0));
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++) {
			ans = max(ans, findExceptSum(i, j));
		}
	}
	cout << ans;
	/////////////////////////////////////////////////////////////////
	return 0;
}