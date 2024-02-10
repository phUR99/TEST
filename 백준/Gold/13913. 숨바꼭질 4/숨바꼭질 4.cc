#include <bits/stdc++.h>
using namespace std;
// 이전 위치의 정보를  저장하는 nxt 배열
// 고려해야 할 점:시작 위치가 0이라면? 시작 위치와 도착 위치가 동일하다면?
int dist[100005];
int nxt[100005];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	queue<int> q;
	fill(dist, dist + 100005, -1);
	fill(nxt, nxt + 100005, -2);
	q.push(n);
	dist[n] = 0;
	nxt[n] = -1;
	if (n == k) {
		cout << 0 << '\n' << k;
	}
	while (!q.empty())
	{
		int cur = q.front(); q.pop();
		for (auto dir : { cur - 1, cur + 1, cur * 2 }) {
			if (dir < 0 || dir > 100000) continue;
			if (dist[dir] != -1) continue;			
			q.push(dir);
			dist[dir] = dist[cur] + 1;
			nxt[dir] = cur;
			if (dir == k) {
				cout << dist[dir] << '\n';
				int iter = k;
				stack<int> s;			
				while (iter != -1)
				{
					s.push(iter);
					iter = nxt[iter];
				}
				while (!s.empty())
				{
					cout << s.top() << ' ';
					s.pop();
				}
				return 0;
			}
		}
	}
}
