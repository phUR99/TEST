#include <bits/stdc++.h>
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
using namespace std;
int f, b;
bool visited[100005];
int n, m, x;
vector<vector<int>> adj, r_adj;

int solve(int cur, vector<vector<int>> &now)
{
    visited[cur] = true;
    int ret = 1;
    for (auto nxt : now[cur])
    {
        if (visited[nxt])
            continue;
        ret += solve(nxt, now);
    }
    return ret;
}

int main()
{
    fastio;
    cin >> n >> m >> x;
    adj.resize(n + 1);
    r_adj.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        r_adj[v].push_back(u);
    }
    f = solve(x, r_adj) - 1;
    memset(visited, false, sizeof(visited));
    b = solve(x, adj) - 1;

    cout << f + 1 << ' ' << n - b;
    return 0;
}