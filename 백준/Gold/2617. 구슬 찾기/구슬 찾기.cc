#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define X first
#define Y second
int n, m;

vector<int> adj[105], inv_adj[105];

bool bfs(int st, const vector<int> vec[]) {
    queue<int> q;
    bool chk[105];
    fill(chk + 1, chk + n + 1, 0);
    chk[st] = true;
    q.push(st);
    int val = 0;
    while (!q.empty())
    {
        int cur = q.front(); q.pop();
        for (auto nxt : vec[cur]) {
            if (chk[nxt]) continue;
            chk[nxt] = true;
            q.push(nxt);
            val++;
        }
    }
    return val >= (n+1) / 2;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        inv_adj[v].push_back(u);

    }
    int ans = 0;

    for (int i = 1; i <= n ; i++)
    {
        if (bfs(i, adj) || bfs(i, inv_adj)) ans++;
    }
    cout << ans;
    
}