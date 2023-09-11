#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#define X first
#define Y second
using namespace std;
//x/y축이 되게 헷갈린다 잘 파악해서 x축 y축을 사용하자.
bool map[101][101];
bool visited[101][101];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int M, N, K;
	cin >> M >> N >> K;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++) {
			map[i][j] = false;
			visited[i][j] = false;
		}
	}
	while (K--)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int i = y1; i < y2; i++)
		{
			for (int j = x1; j < x2; j++) {
				map[i][j] = true;
			}
		}
	}
	queue<pair<int, int>> q;
	vector<int> ans;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++) {
			if (map[i][j] == true || visited[i][j] == true) continue;
			q.push({ i, j });
			visited[i][j] = true;
			int cnt = 1;
			while (!q.empty())
			{
				pair<int, int> cur = q.front(); q.pop();
				for (int iter = 0; iter < 4; iter++)
				{
					int nx = cur.X + dx[iter];
					int ny = cur.Y + dy[iter];
					if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
					if (visited[nx][ny] == true || map[nx][ny] == true) continue;
					visited[nx][ny] = true;
					cnt++;
					q.push({ nx, ny });
				}
			}
			if (cnt == 0) ans.push_back(1);
			else ans.push_back(cnt);


		}
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for (auto i : ans) 
	{
		cout << i << " ";
	}



	return 0;	
}
