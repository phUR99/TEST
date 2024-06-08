#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;
/*
한 점에 대해서 다른 정점으로 가는 최단거리 ->다익스트라

*/
const int INF = 0x7fffffff;
int node[20005];

struct Edge
{
	int to, cost;
	bool operator<(const Edge &a) const {
		return a.cost < cost;
	}
};

vector<Edge> adj[20005];

int main() {
	//빠른 입출력을 위해서 사용하기
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);

	//init
	int v, e, st;
	cin >> v >> e >> st;

	fill(node + 1, node + v + 1, INF);

	while (e--)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		adj[from].push_back({ to, cost });
	}
	priority_queue<Edge> pq;
	pq.push({ st, 0 });
	node[st] = 0;

	while (!pq.empty())
	{
		auto cur = pq.top(); pq.pop();
		if (node[cur.to] < cur.cost) continue;
		for (auto nxt : adj[cur.to])
		{
			if (node[nxt.to] > cur.cost + nxt.cost) {
				node[nxt.to] = cur.cost + nxt.cost;
				pq.push({ nxt.to, node[nxt.to] });
			}
		}
	}
	for (int i = 1; i <= v; i++)
	{
		if (node[i] == INF) cout << "INF" << '\n';
		else    cout << node[i] << '\n';
	}
	return 0;
}