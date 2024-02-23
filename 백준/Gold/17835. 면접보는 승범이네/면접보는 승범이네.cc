#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
#include <string>
using namespace std;


/*
#1261 : BFS로 dist를 갱신할 때의 문제점... 반복 횟수가 상당히 많아질 것 같은 예감
방문 횟수를 최소할 방법이 필요...
가상의 면접장 설정 : 시작점을 0으로 두고 면접장이랑 잇는다. 그 다음 다익스트라를 실행할 경우 ElogN에 해결 가능
가상의 면접장으로부터 나가는 길만 있어야 한다.
간선의 방향을 뒤집는 것이랑 ans를 확인할 때 INF를 체크해야함
*/
struct Edge
{
	long long cost;
	int to;
	bool operator < (const Edge& a) const {
		return a.cost < cost;
	}
};


long long dist[100005];
int n, m, k;
vector<Edge> adj[100005];

int main() {
	//빠른 입출력을 위해서 사용하기	
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m >> k;
	while (m--)
	{
		int from, to;
		long long cost;
		cin >> to >> from >> cost;
		adj[from].push_back({ cost, to });
	}
	while (k--)
	{
		int to;
		cin >> to;
		adj[0].push_back({ 0, to });
	}
	priority_queue<Edge> pq;
	pq.push({ 0, 0 });

	const long long INF = 1e17;

	fill(dist + 1, dist + n + 1, INF);

	while (!pq.empty())
	{
		Edge cur = pq.top(); pq.pop();

		if (dist[cur.to] < cur.cost) continue;
		for (auto nxt : adj[cur.to])
		{
			if (dist[nxt.to] > cur.cost + nxt.cost) {
				dist[nxt.to] = cur.cost + nxt.cost;
				pq.push({ cur.cost + nxt.cost, nxt.to });
			}
		}
	}
	int idx = 0;
	long long ans = 0;
	for (int i = n; i > 0; i--)
	{
		if (ans <= dist[i] && dist[i] != INF) {
			idx = i;
			ans = dist[i];
		}
	}
	cout << idx << '\n' << ans;
	return 0;
}