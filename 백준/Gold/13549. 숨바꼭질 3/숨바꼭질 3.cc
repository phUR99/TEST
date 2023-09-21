#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
#define MAX 100005
int map[MAX];
int dx[3] = { -1, 1, 2 };
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, K;
	cin >> N >> K;
	fill(map, map + MAX, -1);
	map[N] = 0;
	queue<int> q;
	q.push(N);
	while (!q.empty())
	{
		int cur = q.front(); q.pop();
		for (int i = 0; i < 3; i++)
		{
			int nx, nd;
			if (i == 2) {
				nx = cur * dx[i];
				nd = map[cur];
			}
			else {
				nx = cur + dx[i];
				nd = map[cur] + 1;
			}
			if (nx < 0 || nx >= MAX) continue;
			if (map[nx] != -1 && map[nx] <= nd)  continue;
			map[nx] = nd;
			q.push(nx);

		}
	}
	cout << map[K];


}