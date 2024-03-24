#include <bits/stdc++.h>
using namespace std;

/*
#15683 : 모양에 맞는 회전구조 만들기
방향을 미리 정하고, 정해진 방향에 대해서 각각의 DFS를 실행.
틀린 이유: cur == cnt가 되었을 때 종료했어야 하는데 cur > cnt로 설정해서 스택 오버플로우가 발생함.

*/
int n, m;
int board[8][8];
int arr[8];
const int MX = 987654321;
pair<int, int> tv[8];
int cnt = 0;
int ans = MX;
bool visited[8][8];
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };

void mark(int x, int y, int dir) {
	if (x < 0 || x >= n || y < 0 || y >= m || board[x][y] == 6) return;
	visited[x][y] = true;
	x += dx[dir];
	y += dy[dir];
	mark(x, y, dir);
}


int findMinArea() {
	int ret = 0;
	
	memset(visited, false, sizeof(visited));
	for (int i = 0; i < cnt; i++)
	{
		int x = tv[i].first, y = tv[i].second;

		if (board[x][y] == 1) mark(x, y, arr[i]);
		else if (board[x][y] == 2) {
			mark(x, y, arr[i]);
			mark(x, y, (arr[i] + 2) % 4);
		}
		else if (board[x][y] == 3) {
			mark(x, y, arr[i]);
			mark(x, y, (arr[i] + 1) % 4);
		}
		else if (board[x][y] == 4) {
			mark(x, y, arr[i]);
			mark(x, y, (arr[i] + 1) % 4);
			mark(x, y, (arr[i] + 3) % 4);
		}
		else
		{
			mark(x, y, arr[i]);			
			mark(x, y, (arr[i] + 1) % 4);
			mark(x, y, (arr[i] + 2) % 4);
			mark(x, y, (arr[i] + 3) % 4);
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++) {
			if (visited[i][j] == false && board[i][j] != 6) ret++;

		}
	}

	return ret;
}

void findWay(int cur) {
	
  //틀린부분
	if (cur == cnt)
	{
		ans = min(ans, findMinArea());
		return;
	}
	int x = tv[cur].first;
	int y = tv[cur].second;
	int num = board[x][y];

	if (num == 5) {
		arr[cur] = 0;
		findWay(cur + 1);
		
	}
	else if (num == 2) {
		for (int i = 0; i < 2; i++)
		{
			arr[cur] = i;
			findWay(cur + 1);
		}
	}
	else
	{
		for (int i = 0; i < 4; i++)
		{
			arr[cur] = i;
			findWay(cur + 1);
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
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] != 0 && board[i][j] != 6) {
				tv[cnt] = { i, j };
				cnt++;
			}
		}
	}
	
	findWay(0);
	cout << ans;

	/////////////////////////////////////////////////////////////////
	return 0;
}
