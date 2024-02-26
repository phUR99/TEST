#include <bits/stdc++.h>
using namespace std;
/*
#1937 : dfs 구현 + 가지치기 유의하기 -> 가지치기가 아니라 DP로 설계

d(x, y) : x, y 일 때 가장 오래살 수 있는 일수
d(x, y) = 인접한 4방향 중 최댓값 +1
초기 -1로 초기화 후 시작하면 1로 변경


*/
int n;
int board[505][505];
int d[505][505];
int ans = 0;
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

int func(int x, int y) {
	if (d[x][y] != -1) return d[x][y];
	else
	{
		d[x][y] = 1;
		for (int dir =0; dir <4; dir++)
		{
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (board[nx][ny] <= board[x][y]) continue;
			d[x][y] = max(d[x][y], func(nx, ny) + 1);

		}
		return d[x][y];
	}
}



int main() {
	//빠른 입출력을 위해서 사용하기	
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
			d[i][j] = -1;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			ans = max(ans, func(i, j));
		}
	}
	cout << ans;
	return 0;
}