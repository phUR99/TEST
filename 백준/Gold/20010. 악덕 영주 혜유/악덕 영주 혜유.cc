#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n, m;
vector<vector<pair<int, int>>> adj;
priority_queue<array<int, 3>> arr;
int parent[1005];
int find(int u)
{
    if (u == parent[u])
        return u;
    return parent[u] = find(parent[u]);
}
bool merge(int u, int v)
{
    u = find(u);
    v = find(v);
    if (u == v)
        return false;
    parent[u] = v;
    return true;
}
int mxDist = 0;
int mxNode = -1;
bool visited[1005];
void dfs(int here, int cost)
{
    visited[here] = 1;
    if (cost > mxDist)
    {
        mxDist = cost;
        mxNode = here;
    }
    for (auto nxt : adj[here])
    {
        int w = nxt.first;
        int there = nxt.second;
        if (!visited[there])
            dfs(there, cost + w);
    }
}
int main()
{
    fastio;
    cin >> n >> m;
    adj.resize(n);
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }

    for (int i = 0; i < m; i++)
    {
        array<int, 3> tmp;
        cin >> tmp[1] >> tmp[2] >> tmp[0];
        tmp[0] = -tmp[0];
        arr.push(tmp);
    }
    int ret0 = 0;
    while (!arr.empty())
    {
        auto here = arr.top();
        arr.pop();
        int cost = -here[0];
        int u = here[1];
        int v = here[2];
        if (merge(u, v))
        {
            ret0 += cost;
            adj[u].push_back({cost, v});
            adj[v].push_back({cost, u});
        }
    }
    cout << ret0 << '\n';
    memset(visited, 0, sizeof(visited));
    dfs(0, 0);
    memset(visited, 0, sizeof(visited));
    dfs(mxNode, 0);
    cout << mxDist;
    return 0;
}