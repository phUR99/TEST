#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define X first
#define Y second


vector<int> adj[105];
int ans[105];
int n, m;
int bfs(int it) {
    int dist[105];
    fill(dist + 1, dist + n + 1, -1);
    queue<int> q;
    q.push(it);
    dist[it] = 0;

    while (!q.empty())
    {
        int cur = q.front(); q.pop();
        for (auto nxt : adj[cur])
        {
            if (dist[nxt] != -1) continue;
            dist[nxt] = dist[cur] + 1;
            q.push(nxt);
        }
    }
    int val = 0;
    for (int i = 1; i <= n; i++)
    {
        val += dist[i];
    }
    return val;
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
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        ans[i] = bfs(i);
    }
    cout << min_element(ans + 1, ans + n + 1) - ans;

    
}