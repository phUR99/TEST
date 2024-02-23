#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
#include <string>
using namespace std;


/*
#1238 : 다익스트라
다익스트라가 한 정점에서부터 다른 정점으로 가는 최단 거리인 것을 고려할 때
도착 위치 마을 X 에 대해서 마을로 다시 돌아가는 최단거리의 시간복잡도는 N * ElogN으로 시간초과가 날 것임을 예상 가능
따라서, 다익스트라의 횟수를 줄이기 위해서 간선의 방향을 반대로 바꾸는 그래프를 만든 후 그 떄의 최단거리를 구하면 ElogN에 해결 가능
*/

int dist[1005], iDist[1005];
const int MX = 1000000000 + 1;
int n, m, x;

struct Edge
{
	int cost, to;
	bool operator<(const Edge& a) const {
		return a.cost < cost;
	}
};


vector<Edge> adj[1005], iAdj[1005];

int main() {
	//빠른 입출력을 위해서 사용하기	
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m >> x;
	while (m--)
	{
		int from, to, cost;
		cin >> from >> to >> cost;

		adj[from].push_back({ cost, to });
		iAdj[to].push_back({ cost, from });
	}

	fill(dist, dist + n + 1, MX);
	fill(iDist, iDist + n + 1, MX);

	priority_queue<Edge> pq;
	dist[x] = 0; iDist[x] = 0;
	pq.push({ 0, x });

	while (!pq.empty())
	{
		auto cur = pq.top(); pq.pop();
		if (dist[cur.to] < cur.cost) continue;

		for (auto nxt : adj[cur.to])
		{
			if (dist[nxt.to] > cur.cost + nxt.cost) {
				dist[nxt.to] = cur.cost + nxt.cost;
				pq.push({ cur.cost + nxt.cost, nxt.to });
			}
		}
	}
	pq.push({ 0, x });
	while (!pq.empty())
	{
		auto cur = pq.top(); pq.pop();
		if (iDist[cur.to] < cur.cost) continue;

		for (auto nxt : iAdj[cur.to])
		{
			if (iDist[nxt.to] > cur.cost + nxt.cost) {
				iDist[nxt.to] = cur.cost + nxt.cost;
				pq.push({ cur.cost + nxt.cost, nxt.to });
			}
		}
	}
	int ans = 0;

	for (int i = 1; i <= n; i++)
	{
		ans = max(ans, dist[i] + iDist[i]);
	}
	
	cout << ans;


	return 0;
}