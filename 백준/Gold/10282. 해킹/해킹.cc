#include <bits/stdc++.h>
using namespace std;
/*
#10282 : 정직한 다익스트라 구현

*/

const int INF = 987654321;
int dist[10005];
int n, m, t, st;
struct node
{
	int cost, to;

	bool operator < (const node& a) const {
		return a.cost < cost;
	}
};
vector<node> adj[10005];


int main() {	
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
	/////////////////////////////////////////////////////////////////
	cin >> t;
	while (t--)
	{
		int cnt = 0, distMax = 0;

		cin >> n >> m >> st;

		while (m--)
		{
			int from, to, cost;
			cin >> to >> from >> cost;
			adj[from].push_back({ cost, to });			
		}

		fill(dist + 1, dist + n + 1, INF);
		priority_queue<node> pq;
		pq.push({ 0, st });
		dist[st] = 0;

		while (!pq.empty())
		{
			auto cur = pq.top(); pq.pop();
			if (dist[cur.to] < cur.cost) continue;

			for (auto nxt : adj[cur.to])
			{
				if (dist[nxt.to] <= cur.cost + nxt.cost) continue;
				dist[nxt.to] = cur.cost + nxt.cost;
				pq.push({ cur.cost + nxt.cost, nxt.to });
			}
		}
		for (int i = 1; i <= n; i++)
		{
			if (dist[i] == INF) continue;
			cnt++;
			distMax = max(distMax, dist[i]);
		}
		cout << cnt << ' ' << distMax << '\n';
		for (int i = 1; i <= n; i++)
		{
			adj[i].clear();
		}
	}
	

	
	/////////////////////////////////////////////////////////////////
	return 0;
}