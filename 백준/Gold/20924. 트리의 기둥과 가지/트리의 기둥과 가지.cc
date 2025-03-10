#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n, r;
vector<vector<pair<int, int>>> adj;
int dfs(int here, int parent)
{
    if (adj[here].size() > 2 || (parent == -1 && adj[here].size() == 2))
        return here;
    for (auto there : adj[here])
    {
        if (there.second == parent)
            continue;
        return dfs(there.second, here);
    }
    return here;
}
int mxDist = 0;
int Gdist = 0;
int g;

void dfs2(int here, int parent, int dist)
{
    mxDist = max(mxDist, dist);
    if (g == here)
    {
        Gdist = dist;
    }

    for (auto nxt : adj[here])
    {
        int there = nxt.second;
        int cost = nxt.first;
        if (there == parent)
            continue;
        dfs2(there, here, dist + cost);
    }
}
int main()
{
    fastio;
    cin >> n >> r;
    adj.resize(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back({c, v});
        adj[v].push_back({c, u});
    }
    g = dfs(r, -1);
    dfs2(r, -1, 0);
    cout << Gdist << ' ' << mxDist - Gdist;
    return 0;
}