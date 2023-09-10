#include <iostream>
#include <queue>
using namespace std;

int N, M;
int check[101][101]; 
int visit[101][101]; 
char map[101][101]; 
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void bfs(int x, int y) {

	visit[x][y] = 1;
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int x2 = x + dx[i];
			int y2 = y + dy[i];
			if ((0 <= x2 && x2 < N) && (0 <= y2 && y2 < M)) {
				if (map[x2][y2] == '1' && visit[x2][y2] == 0)
				{
					check[x2][y2] = check[x][y] + 1;
					visit[x2][y2] = 1;
					q.push(make_pair(x2, y2));
				}
			}

		}
		
	}
}
int main(){
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> map[i];
	}
	check[0][0] = 1;

	bfs(0, 0);
	cout << check[N - 1][M - 1];
}