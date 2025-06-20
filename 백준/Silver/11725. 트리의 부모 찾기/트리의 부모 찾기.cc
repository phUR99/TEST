#include <bits/stdc++.h>
using namespace std;
#define fastio                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL)
#define ll long long
int n;
vector<vector<int>> adj;
int parent[100005];
void dfs(int here, int p) {
  parent[here] = p;
  for (int nxt : adj[here]) {
    if (nxt == p) continue;
    dfs(nxt, here);
  }
}

int main() {
  fastio;
  cin >> n;
  adj.resize(n + 1);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  dfs(1, -1);
  for (int i = 2; i <= n; i++) {
    cout << parent[i] << '\n';
  }

  return 0;
}