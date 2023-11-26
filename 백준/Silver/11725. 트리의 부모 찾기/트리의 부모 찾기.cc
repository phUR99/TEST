#include <bits/stdc++.h>

using namespace std;
#define ll long long

int n;
//노드의 부모를 찾아줄 배열 p
int p[100'001];
//트리 adj
vector<int> adj[100'001];
//dfs를 통해서 부모를 찾는다.
void dfs(int cur) {
    for (int nxt : adj[cur])
    {
        if (p[cur] == nxt) continue;
        p[nxt] = cur;
        dfs(nxt);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n-1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    for (int i = 2; i <=n; i++)
    {
        cout << p[i] << '\n';
    }
}
