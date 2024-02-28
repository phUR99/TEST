#include <bits/stdc++.h>
using namespace std;
/*
#16118 : 2번의 다익스트라 구하기
2로 나누는 것은 별로 안좋아하니까 미리 2를 다 곱해놓자

*/

const int INF = 987654321;
int distFox[4005], distWolf[4005][2];
int n, m;
struct node
{
	int cost, to;

	bool operator < (const node& a) const {
		return a.cost < cost;
	}
};
struct nodeW
{
	int cost, to, curMove;

	bool operator < (const nodeW& a) const {
		return a.cost < cost;
	}
};

vector<node> adj[4005];
int main() {	
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
	/////////////////////////////////////////////////////////////////
	cin >> n >> m;

	while (m--)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		adj[from].push_back({2 * cost, to });
		adj[to].push_back({2 * cost, from});
	}
	priority_queue<node> pq;
	pq.push({0, 1});
	fill(distFox + 1, distFox + n + 1, INF);
	distFox[1] = 0;

	while (!pq.empty())
	{
		auto cur = pq.top(); pq.pop();
		if (distFox[cur.to] < cur.cost) continue;

		for (auto nxt : adj[cur.to]) {
			if (distFox[nxt.to] <= cur.cost + nxt.cost) continue;
			distFox[nxt.to] = cur.cost + nxt.cost;
			pq.push({ cur.cost + nxt.cost, nxt.to });
		}
	}
	for (int i = 1; i <= n; i++)
	{
		distWolf[i][0] = INF;
		distWolf[i][1] = INF;
	}


	distWolf[1][0] = 0;
	priority_queue<nodeW> pq2;
	pq2.push({ 0, 1, 0 });

	while (!pq2.empty())
	{
		auto cur = pq2.top(); pq2.pop();
		int curMove = cur.curMove;
		if (distWolf[cur.to][curMove] < cur.cost) continue;

		for (auto nxt : adj[cur.to])
		{
			int nxtDist = (curMove == 0) ? nxt.cost / 2 + cur.cost : nxt.cost * 2 + cur.cost;
			if (distWolf[nxt.to][(curMove + 1) % 2] <=  nxtDist) continue;
			distWolf[nxt.to][(curMove + 1) % 2] = nxtDist;
			pq2.push({ nxtDist, nxt.to,  (curMove + 1) % 2 });
			

		}
	}
	int ans = 0;
	for (int i = 2; i <= n; i++)
	{
		if (distFox[i] < min(distWolf[i][0], distWolf[i][1])) ans++;		
	}
	cout << ans;
	/////////////////////////////////////////////////////////////////
	return 0;
}