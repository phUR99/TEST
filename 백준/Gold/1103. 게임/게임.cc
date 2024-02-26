#include <bits/stdc++.h>
using namespace std;
/*
#1103 : dfs + dP + 사이클 판단

사이클 : 방문 배열 만들어서 해결


*/
int n, m;
int board[55][55];
int d[55][55];
bool vis[55][55];

int ans = 0;
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

int func(int x, int y) {
	// 내가 좌표의 바깥이나 H에 도달했다면 0을 반환하고 종료.
	if (x < 0 || x >= n || y < 0 || y >= m || board[x][y] == 0) return 0;
	// 내가 이전에 방문했던 곳을 다시 방문했다면 사이클이 생긴 것이므로 -1를 출력하고 탈출
	if (vis[x][y] == true) {
		cout << -1;
		exit(0);
	}
	// 이전에 값을 계산해 놓은 곳이면 (방문했지만 dfs의 종료로 인해서 vis을 지운 상태) 그 값을 반환해준다.
	if (d[x][y] != -1) return d[x][y];
	// 이전에 값을 계산해 주지 않았다면
	else
	{
		// 값을 초기화를 해준 후
		d[x][y] = 0;
		vis[x][y] = true;
		for (int i = 0; i < 4; i++)
		{
			// 갈 수 있는 방향에 대해서 전부 체크를 해준다
			int nx = x + board[x][y] * dx[i];
			int ny = y + board[x][y] * dy[i];
			d[x][y] = max(d[x][y], func(nx, ny) + 1);
		}
		// 방문 종료 후 d를 반환해준다.
		vis[x][y] = false;
		return d[x][y];
	}
	
}



int main() {
	//빠른 입출력을 위해서 사용하기	
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			char c;
			cin >> c;
			if (c == 'H')
			{
				board[i][j] = 0;
			}
			else board[i][j] = c - '0';
			d[i][j] = -1;
		}
	}
	ans = func(0, 0);
	cout << ans;
	return 0;
}