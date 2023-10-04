
//d[a][b] = (a, b)에서는 (N - 1, M - 1) 까지 c개의 경로로 도달할 수 있습니다."
//즉, 탐색을 하다가 기존에 탐색을 한 좌표에 중복적으로 도달할 경우, 더 이상의 탐색을 필요로 없이 DP[][] 값을 통해서 바로 경로의 갯수를 알아낼 수 있는 것이다.
//DP배열의 모든 값들을 ' -1 ' 로 초기화 시켜 주었다. 0이 아닌 -1로 시켜준 이유는, 특정 좌표에서(N - 1, M - 1)까지 갈 수 있는 경로가 없을 경우에는 DP[][] 값에 0 이 저장될 것이다.
//처음에 본인은 단순 DFS로 답을 출력 후 제출을 했지만 시간초과가 발생했다
   
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <math.h>
#include <tuple>
#include <numeric>
using namespace std;
#define ll long long
int map[505][505];
int d[505][505];
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };
int m, n;
int dfs(int x, int y) {
	if (x == m - 1 && y == n - 1) return 1;
	if (d[x][y] != -1) return d[x][y];
	d[x][y] = 0;
	for (int iter = 0; iter < 4; iter++)
	{
		int nx = x + dx[iter];
		int ny = y + dy[iter];
		if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
		if (map[nx][ny] >= map[x][y]) continue;
		d[x][y] += dfs(nx, ny);
	}
	return d[x][y];
}


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);


	cin >> m >> n;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			d[i][j] = -1;
		}
	}
	cout << dfs(0, 0);
	
	
}
