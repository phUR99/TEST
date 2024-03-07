#include <bits/stdc++.h>
using namespace std;
/*
#15686 : 연구소 문제와는 다르게 조합을 반드시 DFS를 이용한 형태로 사용해야 함

*/
const int MX = 987654321;
int n, m;
int ans = MX;
int board[50][50];

int arr[13];

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, -1, 0, 1 };

int minDist(const int (&arr)[13]) {
	int ret = 0;
	queue<pair<int, int>> q;

	int dist[50][50];
	memset(dist, -1, sizeof(dist));

	for (int i = 0; i < m; i++)
	{
		int x = arr[i] / n;
		int y = arr[i] % n;
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
			if (dist[nx][ny] != -1) continue;
			dist[nx][ny] = dist[cur.first][cur.second] + 1;
			q.push({ nx, ny });
		}
	}
	for (int i = 0; i < n; i++)
	{		
		for (int j = 0; j < n; j++)
		{
			if (board[i][j] == 1) ret += dist[i][j];
		}

	}
	return ret;

}
void comb(int cur, int cnt) {
	if (cnt == m ) {

		ans = min(ans, minDist(arr));
		return;
	}
	else
	{
		//헤멘 부분 1 : cur=0일 때의 예외처리를 어려워했다
    //그냥 0일때는 예외를 주는 방식으로 하자
    
		for (int i = (cur == 0 ? 0 : cur+1); i < n * n; i++)
		{
    //헤멘 부분 2 : 2인 것을 체크하고 그 값을 array에 넣어줬어야 하는데 밖에 넣어줘서 2가 아닌데도 array가 갱신되는 문제가 있었다.
    //앞으로는 이런 체크를 웬만하면 기저조건으로 처리하는 것이 맞을 것 같다.
			if (board[i / n][i % n] != 2) continue;
			arr[cnt] = i;
			comb(i, cnt + 1);	
		}
	}
	return;
}


int main() {
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
	/////////////////////////////////////////////////////////////////
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	comb(0, 0);
	cout << ans;
	/////////////////////////////////////////////////////////////////
	return 0;
}
