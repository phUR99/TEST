#include <bits/stdc++.h>
using namespace std;

/*
DP + 다익스트라
1. 간선 M개 에 대해서 K개를 빼면서 다익스트라 : 시간초과
2. dist의 배열을 k개 만든다
3. 최소 힙에 K는 상관 없이 최단 거리대로 넣되, k의 정보를 같이 담아서 dP로 설계한다
4. 답은 dist의 정점에 해당하는 거리의 최솟값.

시간초과가 난 이유 : numk == k 일 때만 중단시키려고 했는데 생각해보니 필요가 없었음
오류가 난 이유 : dist가 int MX의 값을 넘어갈 수 도 있다는 것을 생각못함. n * cost = 1e12여서 생각하지 않았는데 21억이 1e10이 안되므로 long long을 사용하는 것이 맞았다.
*/
struct Edge
{
	long long cost;
	int to;

	bool operator< (const Edge& a) const {
		return a.cost < cost;
	}
};
struct element
{
	long long cost;
	int to, numk;

	bool operator< (const element& a) const {
		return a.cost < cost;
	}
};


vector<Edge> adj[10005];
long long dist[25][10005];
int n, m, k;
const long long INF = 1e15;
bool isAns[25];



int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> k;
	for (int i = 0; i <= k; i++)
	{
		fill(dist[i] +1, dist[i] + n + 1, INF);
	}
	
	priority_queue<element> pq;
	
	while (m--)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		adj[from].push_back({ cost, to });
		adj[to].push_back({ cost, from });
	}
	dist[0][1] = 0;
	pq.push({0, 1, 0});

	while (!pq.empty())
	{
		auto cur = pq.top(); pq.pop();
		

		if (dist[cur.numk][cur.to] < cur.cost) continue;

		for (auto nxt : adj[cur.to])
		{
			if (dist[cur.numk][nxt.to] > cur.cost + nxt.cost) {
				
				
				if (cur.numk < k && dist[cur.numk + 1][nxt.to] > cur.cost)
				{
					dist[cur.numk+1][nxt.to] = cur.cost;					
					pq.push({cur.cost, nxt.to, cur.numk+1});
				}				
				dist[cur.numk][nxt.to] = cur.cost + nxt.cost;
				pq.push({cur.cost + nxt.cost, nxt.to, cur.numk});

			}

		}
		
	}
	long long ans = 1e15;
	for (int i = 0; i <= k; i++)
	{
		ans = min(ans, dist[i][n]);
	}
	cout << ans;
}
