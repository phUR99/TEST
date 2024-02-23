#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
#include <string>
using namespace std;


/*
#13907 : dist[n][k] 배열로 k에 따른 최단거리를 전부 저장한다.
공간복잡도 10^3 * 10^3 한 줄로 그래프가 다 이어도 1000을 넘지 않는다.
연산횟수 30000 * 1000 = 3천만번...

*/
struct Edge
{
	int cost;
	int to;
	bool operator < (const Edge& a) const {
		return a.cost < cost;
	}
	
};
struct element
{
	int cost, to, num;
	
	bool operator < (const element& a) const {
		return a.cost < cost;
	}
};


int dist[1005][1005];
vector<Edge> adj[1005];
int n, m, k, st, ed;

int main() {
	//빠른 입출력을 위해서 사용하기	
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m >> k >> st >> ed;
	while (m--)
	{
		int from, to, cost;
		cin >> to >> from >> cost;
		adj[from].push_back({ cost, to });
		adj[to].push_back({ cost, from });
	}
	
	priority_queue<element> pq;
	

	const int INF = 1e9;
	for (int i = 0; i <= n; i++)
	{
		fill(dist[i], dist[i] + n + 1, INF);

	}
	
	dist[st][0] = 0;
	pq.push({ 0, st, 0 });
	while (!pq.empty())
	{
		element cur = pq.top(); pq.pop();

		if (dist[cur.to][cur.num] < cur.cost) continue;
		for (auto nxt : adj[cur.to])
		{
			if (dist[nxt.to][cur.num +1] > cur.cost + nxt.cost) {
				dist[nxt.to][cur.num +1] = cur.cost + nxt.cost;
				pq.push({ cur.cost + nxt.cost, nxt.to, cur.num + 1});
			}
		}
	}
	cout << *min_element(dist[ed] + 1, dist[ed] + n) << '\n';
	for (int i = 0; i < k; i++)
	{
		int up;
		cin >> up;
		for (int j = 1; j < n; j++) {
			dist[ed][j] += up * j;
		}
		cout << *min_element(dist[ed] + 1, dist[ed] + n) << '\n';
	}
	return 0;
}