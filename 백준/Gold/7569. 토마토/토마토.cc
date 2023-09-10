#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#define X first
#define Y second
using namespace std;
//1. 3차원 이상의 좌표를 다루기 위해서는 tuple 자료형을 사용할 수 있음
//2. 뭐가 뭐의 좌표인지 잘 보자
//3. 시간을 거리로 치환해서 보면은 결국 전부 다 도달하는 데 필요한 거리가 답이란 것을 알 수 있음..
//그러니까 다 도달했을 때의 거리의 최대값을 답으로 출력하면 될 것 같다.
int map[101][101][100];
int dist[101][101][101];
int dx[6] = { 1, 0, 0, -1, 0, 0 };
int dy[6] = { 0, 1, 0, 0, -1, 0 };
int dz[6] = { 0, 0, 1, 0, 0, -1 };

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int m, n, h;
	//pair가 아니라 tuple<int, int, int> 이런 식으로 선언할 수 있다.
	queue<pair<int, pair<int, int>>> q;
	cin >> m >> n >> h;
	for (int i = 0; i < h; i++)
	{
		//이부분에서 가로 세로가 반대로 들어갔어야 하는데 그것을 캐치하지 못함.
		for (int j = 0; j <n; j++) {
			for (int k = 0; k < m; k++)
			{
				cin >> map[j][k][i];
				if (map[j][k][i] == 1) {
					q.push({ j, {k, i} });
					dist[j][k][i] = 0;
				}
				else dist[j][k][i] = -1;
			}
		}
	}
	int day = 0;
	while (!q.empty())
	{

		pair<int, pair<int, int>> cur = q.front(); q.pop();
		for (int iter = 0; iter < 6; iter++)
		{
			int nx = cur.X + dx[iter];
			int ny = cur.Y.X + dy[iter];
			int nz = cur.Y.Y + dz[iter];
			int nd = dist[cur.X][cur.Y.X][cur.Y.Y] + 1;
			if (nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h) continue;
			//dist가 0보다 크다는 것은 최소 한 번은 방문했다는 것
			//visited의 활용의 응용으로..
			if (dist[nx][ny][nz] >= 0 || map[nx][ny][nz] == -1) continue;
			dist[nx][ny][nz] = nd;
			q.push({ nx, {ny, nz} });
			if (nd > day) day = nd;
		}
	}
	//마지막으로 전부 순회하면서 익지 않은 토마토가 있는 지를 체크
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++)
			{
				if (map[j][k][i] == 0) if (dist[j][k][i] == -1) {
					cout << -1;
					return 0;
				}
			}
		}
	}
	cout << day;
	return 0;
	
}
