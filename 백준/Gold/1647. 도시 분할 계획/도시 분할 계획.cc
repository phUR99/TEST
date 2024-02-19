#include <bits/stdc++.h>
using namespace std;
/*
MST 구하기
1. union_find 활용
*/
int parent[100005];

struct Edge
{
	int from, to, cost;

};
bool cmp(const Edge& a, const Edge& b) {
	return a.cost < b.cost;
}
vector<Edge> adj;
void uni(int a, int b) {
	int ar = parent[a];
	int br = parent[b];
	if (ar < br) {
		parent[br] = ar;
	}
	else parent[ar] = br;
	
}
int find(int a) {
	if (parent[a] == a) return a;
	else return parent[a] = find(parent[a]);
}
int n, m;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i=0; i<m; i++)
	{
		int f, t, c;
		cin >> f >> t >> c;
		adj.push_back({ f, t, c });
	}
	long long ans = 0;
	sort(adj.begin(), adj.end(), cmp);
	for (int i = 1; i <= n; i++)
	{
		parent[i] = i;
	}
	int M = 0;
	for (int i = 0; i < m; i++)
	{
		if (find(adj[i].from) == find(adj[i].to)) continue;
		uni(adj[i].from, adj[i].to);

		ans += adj[i].cost;
		M = max(adj[i].cost, M);
	}
	cout << ans - M;

}