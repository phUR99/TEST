#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int mxNode = -1, mxDist = -1;
bool visited[50005];
int cache[50005];
vector<vector<pair<int, int>>> adj;
void dfs(int here, int sum)
{
    visited[here] = true;
    if (sum > mxDist)
    {
        mxDist = sum;
        mxNode = here;
    }
    for (auto nxt : adj[here])
    {
        int w = nxt.first;
        int there = nxt.second;
        if (!visited[there])
        {
            dfs(there, sum + w);
        }
    }
}
void solve(int here, int parent, int sum)
{
    cache[here] = max(sum, cache[here]);
    for (auto nxt : adj[here])
    {
        int w = nxt.first;
        int there = nxt.second;
        if (there != parent)
        {
            solve(there, here, sum + w);
        }
    }
}
int n;
int main()
{
    fastio;
    cin >> n;
    adj.resize(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back({c, v});
        adj[v].push_back({c, u});
    }
    memset(visited, 0, sizeof(visited));
    dfs(1, 0);
    solve(mxNode, -1, 0);
    memset(visited, 0, sizeof(visited));
    dfs(mxNode, 0);
    solve(mxNode, -1, 0);
    for (int i = 1; i <= n; i++)
    {
        cout << cache[i] << '\n';
    }

    return 0;
}