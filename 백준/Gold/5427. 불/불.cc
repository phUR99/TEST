#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#define X first
#define Y second
using namespace std;
//1. impossible 여러개를 처리할 방법 : 나는 함수를 선언해서 두번째는 그쪽으로 빼줌.
//2. 주의사항 d1을 초기화 시킬 때 -1을 주기 때문에 불이 지나가지 못한 곳에서는 d1의 값이 -1로 선언되어있어 nd >= d1 조건에서 문제가 생겼다.
//3 이는 d1이 -1이면 제외하는 조건을 걸어줌으로써 해결 가능하다.
char map[1001][1001];
int d1[1001][1001];
int d2[1001][1001];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int BFS(queue<pair<int, int>>& q2, int w, int h) {
	while (!q2.empty())
	{
		pair<int, int> cur = q2.front(); q2.pop();
		for (int iter = 0; iter < 4; iter++)
		{
			int nx = cur.X + dx[iter];
			int ny = cur.Y + dy[iter];
			int nd = d2[cur.X][cur.Y] + 1;
			if (nx < 0 || nx >= h || ny < 0 || ny >= w) {
				cout << nd << '\n';
				return 0;
			}
			if (d2[nx][ny] >= 0 || map[nx][ny] != '.' || d1[nx][ny] != -1 && d1[nx][ny] <= nd ) continue;
	
			d2[nx][ny] = nd;
			q2.push({ nx, ny });
		}
	}
	cout << "IMPOSSIBLE" << '\n';
	return 0;
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	while (n--)
	{
		int w, h;
		cin >> w >> h;
		queue<pair<int, int>> q1, q2;
		for (int i = 0; i < h; i++) {
			string temp;
			cin >> temp;			
			for (int j = 0; j < w; j++)
			{
				map[i][j] = temp[j];
				d1[i][j] = -1;
				d2[i][j] = -1;
				if (temp[j] == '*') {
					d1[i][j] = 0;
					q1.push({ i, j });
				}
				else if (temp[j] == '@') {
					d2[i][j] = 0;
					q2.push({ i, j });
				}
			}		
		}
		while (!q1.empty())
		{
			pair<int, int> cur = q1.front(); q1.pop();
			for (int iter = 0; iter < 4; iter++)
			{
				int nx = cur.X + dx[iter];
				int ny = cur.Y + dy[iter];
				int nd = d1[cur.X][cur.Y] + 1;
				if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
				if (d1[nx][ny] >= 0 || map[nx][ny] == '#') continue;
				d1[nx][ny] = nd;
				q1.push({ nx, ny });
			}
		}
		BFS(q2, w, h);
	}

	return 0;
	
}
