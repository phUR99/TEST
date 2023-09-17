#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <tuple>
#define X first
#define Y second
using namespace std;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int map[305][305];
int cnt[305][305];
bool visited[305][305];
int row, col;
//map이 0이 아닌 점을 찾기
//0이 아닌 점에서 동서남북으로 탐색해서 0의 개수를 찾기
//cnt를 선언해서 그 개수를 집어넣고, 탐색이 다 끝나면 map-cnt를 하기. cnt가 더 크다면 0으로 바꿔주기
//처리를 한번 해준 후에 숫자가 남아있는 원소들만 BFS를 해서 개수를 세기

void run(queue<pair<int, int>> &q) {
	while (!q.empty())
	{
		pair<int, int> cur = q.front(); q.pop();
		for (int iter = 0; iter < 4; iter++)
		{
			int nx = cur.X + dx[iter];
			int ny = cur.Y + dy[iter];
			if (nx < 0 || nx >= row || ny < 0 || ny >= col)continue;
			if (map[nx][ny] > 0) continue;
			cnt[cur.X][cur.Y]++;
		}
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++) {
			map[i][j] = (map[i][j] > cnt[i][j]) ? map[i][j] - cnt[i][j] : 0;
		}
	}

}
int n;
void chk(int i, int j) {
	queue<pair<int, int>> cur;
	cur.push({ i, j });
	visited[i][j] = true;
	while (!cur.empty())
	{
		pair<int, int> c = cur.front(); cur.pop();
		for (int iter = 0; iter < 4; iter++)
		{
			int nx = c.X + dx[iter];
			int ny = c.Y + dy[iter];
			if (nx < 0 || nx >= row || ny < 0 || ny >= col)continue;
			if (map[nx][ny] == 0 || visited[nx][ny] == true) continue;
			visited[nx][ny] = true;
			cur.push({ nx, ny });
		}
	}
}


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> row >> col;
	int time = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++) {
			cin >> map[i][j];
		}
	}

	while (true)
	{
		n = 0;
		queue<pair<int, int>> q;
		for (int i = 0; i < row; i++)
		{
			fill(cnt[i], cnt[i] + col, 0);
			fill(visited[i], visited[i] + col, false);
			for (int j = 0; j < col; j++) {
				if (map[i][j] > 0) q.push({ i, j });
			}
		}
		run(q);

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++) {
				if (map[i][j] == 0 || visited[i][j] == true) continue;
				chk(i, j);
				n++;
			}
		}
		time++;
		if (n > 1) {
			cout << time;
			return 0;
		}
		int max_h = 0;
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++) {
				max_h = max(max_h, map[i][j]);
			}
		}
		if (max_h == 0) {
			cout << 0;
			return 0;
		}

	}
}
