#include <iostream>
#include <queue>
using namespace std;


int map[1001][1001];
bool check[1001][1001];
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
int cnt[1001][1001];
queue<pair<int, int>> q;
int N, M;
void bfs() {
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			int Cnt = cnt[x][y];
			if (nx >=0 && nx < M && ny >=0 && ny < N &&! check[nx][ny]&& map[nx][ny]==0)
			{
				check[nx][ny] = true;
				q.emplace(nx, ny);
				cnt[nx][ny] = Cnt + 1;
			}
		}
	}
}

int main() {

	cin >> N >> M;
	

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
			if (map[i][j]==1)
			{
				q.emplace(i, j);
				check[i][j] = true;
			}
		}
	}

	bfs();
	int m = 0;
	int carry = 0;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			
			if (map[i][j] == 0 && !check[i][j])
			{
				cout << -1;
				carry = 1;
				break;
				
			}
			if (m <= cnt[i][j]) {
				m = cnt[i][j];
			}
			
		}
		if (carry == 1) break;

	}
	if (carry == 0) cout << m;
	
}