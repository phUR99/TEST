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
\
	while (true) {
		
		if (map[x][y] == 0) ans++;
		map[x][y] = -1; 
		bool cleaned = false; 
		for (int i = 0; i < 4; i++) {
			d = (d + 3) % 4; 
			if (map[x + dx[d]][y + dy[d]] == 0) {
				x += dx[d];
				y += dy[d];
				cleaned = true;
				break;
			}
		}
		if (cleaned) continue;
		
		if (map[x - dx[d]][y - dy[d]] == 1)
			break;
		
		x -= dx[d];
		y -= dy[d];
	}
	cout << ans;

}