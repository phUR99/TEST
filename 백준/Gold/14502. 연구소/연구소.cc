#include <bits/stdc++.h>
using namespace std;
/*
#14502 : 
64C3 * 64(BFS) 64 * 63 * 62 / 3! * 64 ~3e6
1. board에서 가능한 벽의 후보를 찾는다. 
1-1. 후보는 0이어야 한다.
1_2. 순서는 오름차순으로 강제
1_3. n*m까지의 배열을 만든 후에 3개의 숫자를 선택 m*nC3 -> 좌표 변환 num = n * x + m;

2. 벽을 세운다.
3. BFS를 실행한다.
4. 벽이 아니면서 방문하지 않은 점의 개수를 센다.
5. 그 값의 최솟값을 반환한다.
*/
int n, m;
int board[64][64];
bool visited[64][64];

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };

int solution() {
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 2) {
				q.push({ i, j });
				visited[i][j] = true;
			}
		}
	}
	int ret = 0;
	while (!q.empty())
	{
		auto cur = q.front(); q.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (visited[nx][ny] == true || board[nx][ny] != 0) continue;
			q.push({ nx, ny });
			visited[nx][ny] = true;
		}

	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 0 && visited[i][j] == false) ret++;
		}
	}

	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
	/////////////////////////////////////////////////////////////////
	cin >> n >> m;
	queue<pair<int, int>> q;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
		}
	}
	int ans = 0;

	int boardSize = n * m;
	for (int i = 0; i < boardSize; i++)
	{
		if (board[i / m][i % m] != 0) continue;
		for (int j = i+1; j < boardSize; j++)
		{
			if (board[j / m][j % m] != 0) continue;
			for (int k = j+1; k < boardSize; k++)
			{
				if (board[k / m][k % m] != 0) continue;

				visited[i / m][i % m] = true;
				visited[j / m][j % m] = true;
				visited[k / m][k % m] = true;
				ans = max(ans, solution());
				memset(visited, false, sizeof(visited));
			}
		}
	}
	cout << ans;

	/////////////////////////////////////////////////////////////////
	return 0;
}