#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
//간선 리스트
//a가 가능한 점 -> a로 갈 수 있는 정점 + a에서 갈 수 있는 정점의 수가 n-1

struct Edge
{
	int from, to, cost;

};
bool cmp(const Edge &a, const Edge &b) {
	return a.cost < b.cost;
}
vector<Edge> adj;
int parent[1005];
int n, m;

int find(int a) {
	if (parent[a] == a)  return a;
	else return parent[a] = find(parent[a]);
}
//예약어 있어서 uni로 선언
void uni(int a, int b) {
	int aRoot = find(a);
	int bRoot = find(b);
	if (aRoot < bRoot) parent[bRoot] = aRoot;
	else parent[aRoot] = bRoot;
}

int main() {
	//빠른 입출력을 위해서 사용하기
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
	//init
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		parent[i] = i;
	}


	for(int i=0; i<m; i++)
	{
		int cost, a, b;
		cin >> a >> b >> cost;
		adj.push_back({ a, b, cost });

	}	
	long long ans = 0;
	sort(adj.begin(), adj.end(), cmp);
	

	for (int i = 0; i < m; i++)
	{
		if (find(adj[i].from) != find(adj[i].to)){
			uni(adj[i].from, adj[i].to);
			ans += adj[i].cost;
		}
	}
	cout << ans;

	return 0;
}