#include <bits/stdc++.h>
using namespace std;
const int MX = 987654321;
/*
#17142 : 2의 개수 중에서 m개를 뽑고 BFS를 실행한 후에 최댓값을 센다 -> 50*50 *10C5 -> 600000

*/


bool visited[101];
vector<int> adj[101];
int n;
int st, ed;
int m;

int DFS(int st, int cnt) {
	if (st == ed) {
		return cnt;
	}
	int ret = -1;
	for (auto nxt : adj[st])
	{
		if (visited[nxt] == true) continue;
		visited[nxt] = true;
		ret = max(ret, DFS(nxt, cnt + 1));
		visited[nxt] = false;
	}

	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
	/////////////////////////////////////////////////////////////////
	cin >> n >> st >> ed >> m;
	while (m--)
	{
		int u, v;
		cin >> u >> v;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int ans = DFS(st, 0);
	cout << ans;
	/////////////////////////////////////////////////////////////////
	return 0;
}