#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, num;
bool visit[50][50];
int map[50][50];
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };
int cnt = 0;

void bfs(int x, int y) {
	queue<pair<int,int>> q;
	q.emplace(x, y);
	visit[x][y] = true;

	while (!q.empty())
	{
		int X = q.front().first;
		int Y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			if (X + dx[i] >= 0 && X + dx[i] < N && Y + dy[i] >= 0 && Y + dy[i] < M && !visit[X + dx[i]][Y + dy[i]] && map[X+dx[i]][Y+dy[i]]==1) {
				visit[X + dx[i]][Y + dy[i]] = true;
				q.emplace(X + dx[i], Y + dy[i]);
			}

		}
	}
}
void reset() {
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			visit[i][j] = false;
			map[i][j] = 0;

		}
	}
	cnt = 0;
}
int main() {
	int k;
	cin >> k;
	vector<int> cntQ;
	for (int i = 0; i < k; i++)
	{
		cin >> N >> M >> num;
		for (int i = 0; i < num; i++)
		{
			int x, y;
			cin >> x >> y;
			map[x][y] = 1;
		}
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (map[i][j] == 1 && !visit[i][j])
				{
					bfs(i, j);
					cnt++;
				}

			}
		}
		cntQ.push_back(cnt);
		reset();

	}
	for (auto i : cntQ )
	{
		cout << i << '\n';
	}

}