#include <bits/stdc++.h>
using namespace std;
/*
한 행성과 행성을 잇는 길이 3개가 있고 이 중에서 하나를 선택하는 MST
완전 탐색시 시간 초과
-> 정렬한 값을 관찰해 봤을 때, 거리의 최솟값은 항상 정렬한 값에서 나타나는 것을 관찰할 수 있음.
-> x, y, z를 정렬한 후에  MST를 진행한다.
*/
vector<pair<int, int>> adj[100005];

struct Edge
{
	int from, cost, to;
	bool operator<(const Edge& a) const {
		return a.cost < cost;
	}
};
vector<pair<int, int>> x, y, z;
int n;
bool isused[100005];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int tx, ty, tz;
		cin >> tx >> ty >> tz;
		x.push_back({ tx, i });
		y.push_back({ ty, i });
		z.push_back({ tz, i });
	}
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	sort(z.begin(), z.end());
	for (int i = 0; i < n-1; i++)
	{
		int from = x[i].second;
		int to = x[i + 1].second;
		int cost = x[i + 1].first - x[i].first;
		adj[from].push_back({ cost, to });
		adj[to].push_back({ cost, from });
	}
	for (int i = 0; i < n - 1; i++)
	{
		int from = y[i].second;
		int to = y[i + 1].second;
		int cost = y[i + 1].first - y[i].first;
		adj[from].push_back({ cost, to });
		adj[to].push_back({ cost, from });
	}
	for (int i = 0; i < n - 1; i++)
	{
		int from = z[i].second;
		int to = z[i + 1].second;
		int cost = z[i + 1].first - z[i].first;
		adj[from].push_back({ cost, to });
		adj[to].push_back({ cost, from });
	}
	priority_queue<Edge> pq;
	int cnt = 0;
	isused[1] = true;
	for (auto nxt : adj[1])
	{
		Edge tmp;
		tmp.from = 1;
		tmp.to = nxt.second;
		tmp.cost = nxt.first;
		pq.push(tmp);
	}
	long long ans = 0;
	while (cnt < n-1)
	{
		Edge cur = pq.top(); pq.pop();
		if (isused[cur.to] == true) continue;
		ans += cur.cost;
		isused[cur.to] = true;
		cnt++;
		for (auto nxt : adj[cur.to])
		{
			if (isused[nxt.second] == true) continue;
			pq.push({ cur.to, nxt.first, nxt.second });
		}

	}
	cout << ans;
}