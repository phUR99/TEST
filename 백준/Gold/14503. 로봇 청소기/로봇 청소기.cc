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
int ans = 0;
int map[55][55];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
// 코드를 간결하게 짤 수 있도록 노력하자.
// 재귀보다는 반복문으로 해결할 수 있도록

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	int x, y, d;
	cin >> x >> y >> d;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];

		}
	}
	// 굳이 재귀로 해결하는 게 아니라 더 간단한 방법으로 해결하려고 노력해야 할 것 같다.
	while (true) {
		// 청소하지 않았다면 청소한 후 값을 올려준다.
		if (map[x][y] == 0) ans++;
		// 청소했으니 체크
		map[x][y] = -1; 
		// 4방향에서 청소 여부를 체크하기 위한 수단 
		bool cleaned = false; 
		for (int i = 0; i < 4; i++) {
			// 왼쪽으로 돌면서 확인(바로 반시계 방향으로 돌리는 것에 주의)
			d = (d + 3) % 4; 
			// 청소하지 않았다면
			if (map[x + dx[d]][y + dy[d]] == 0) {
				// 그 방향으로 진행시켜주고
				x += dx[d];
				y += dy[d];
				//청소 가능 여부를 체크한 뒤
				cleaned = true;
				break;
			}
		}
		// 돌아가서 반복
		if (cleaned) continue;
		// 4방향 청소가 전부 불가능하므로
		// 후진할 수 있는지를 체크
		// 불가능하다면 종료
		if (map[x - dx[d]][y - dy[d]] == 1)
			break;
		//가능하다면 후진
		x -= dx[d];
		y -= dy[d];
	}
	cout << ans;

}
