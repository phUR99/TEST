#include <bits/stdc++.h>
using namespace std;
const int MX = 987654321;
/*
#17142 : 2의 개수 중에서 m개를 뽑고 BFS를 실행한 후에 최댓값을 센다 -> 50*50 *10C5 -> 600000

*/
int virusArr[10];
int board[50][50];
int cnt = 0;
int n, m;
int ans = MX;
int dist[50][50];

const int dx[] = { -1, 0, 1, 0 };
const int dy[] = { 0, 1, 0, -1 };

int findMaxDist() {
	int ret = 0;
	queue<pair<int, int>> q;
	memset(dist, -1, sizeof(dist));

	for (int i = 0; i < m; i++)
	{
		int x = virusArr[i] / n;
		int y = virusArr[i] % n;
		dist[x][y] = 0;
		q.push({ x, y });
	}

	while (!q.empty())
	{
		auto cur = q.front(); q.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (dist[nx][ny] != -1 || board[nx][ny] == 1) continue;
			dist[nx][ny] = dist[cur.first][cur.second] + 1;
			q.push({ nx, ny });
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) {
			if (board[i][j] == 0 && dist[i][j] == -1) return MX;
			if (board[i][j] == 0) {
				ret = max(ret, dist[i][j]);
			}
		}
	}


	return ret;
}

void findArr(int bef, int cur) {
	if (cur == m) {
		ans = min(ans, findMaxDist());
		return;
	}

	int boardSize = n * n;
	for (int nxt = (bef == 0 ? bef : bef+1) ; nxt < boardSize; nxt++)
	{
		if(board[nxt/n][nxt%n] != 2) continue;
		virusArr[cur] = nxt;
		findArr(nxt, cur +1);
	}
}



int main() {
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
	/////////////////////////////////////////////////////////////////
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{		
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 2) cnt++;
		}
	}
	findArr(0, 0);
	cout << (ans == MX ? -1 : ans);

	/////////////////////////////////////////////////////////////////
	return 0;
}