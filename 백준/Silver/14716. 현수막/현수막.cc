#include <iostream>
#include <queue>
using namespace std;
int dx[] = {1,0,-1,0,1,1,-1,-1};
int dy[] = {0,1,0,-1,1,-1,1,-1};

bool visit[251][251] = { false };
int map[251][251];
int cnt = 0;
int N, M;

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.emplace(x, y);
	while (!q.empty())
	{
		int x2 = q.front().first;
		int y2 = q.front().second;
		visit[x2][y2] = true;
		q.pop();
		for (int i = 0; i < 8; i++)
		{
			if (x2+dx[i]>=0 && x2+dx[i] <= N && y2+dy[i] >=0 && y2+dy[i] <=M && !visit[x2+dx[i]][y2+dy[i]]&&map[x2 + dx[i]][y2 + dy[i]]==1)
			{
				visit[x2 + dx[i]][y2 + dy[i]] = true;
				q.emplace(x2 + dx[i], y2 + dy[i]);
			}
		}
	}
	cnt++;
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (!visit[i][j]&&map[i][j]==1)
			{
				bfs(i, j);

			}
		}
	}
	cout << cnt;
}