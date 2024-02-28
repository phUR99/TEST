#include <bits/stdc++.h>
using namespace std;
/*
#10282 : 정직한 다익스트라 구현

*/

const int INF = 987654321;
int dist[1005];
int vertex[1005];

int n, m;
struct node
{
	int cost, to;

	bool operator < (const node& a) const {
		return a.cost < cost;
	}
};
vector<node> adj[1005];


int main() {	
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
	/////////////////////////////////////////////////////////////////
	cin >> n >> m;
	while (m--)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		adj[from].push_back({ cost, to });
		adj[to].push_back({cost, from});
	}
	priority_queue<node> pq;
	pq.push({0, 1});
	fill(dist + 1, dist + n + 1, INF);
	dist[1] = 0;

	while (!pq.empty())
	{
		auto cur = pq.top(); pq.pop();
		if (dist[cur.to] < cur.cost) continue;

		for (auto nxt : adj[cur.to]) {
			if (dist[nxt.to] <= cur.cost + nxt.cost) continue;
			dist[nxt.to] = cur.cost + nxt.cost;
			vertex[nxt.to] = cur.to;
			pq.push({ cur.cost + nxt.cost, nxt.to });
		}
	}
	cout << n - 1 << '\n';
	for (int i = 2; i <= n; i++)
	{
		cout << vertex[i] << ' ' << i << '\n';
	}
	
	/////////////////////////////////////////////////////////////////
	return 0;
}