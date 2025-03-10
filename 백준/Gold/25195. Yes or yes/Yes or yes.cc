#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n, m, s;
bool fanclub[100001];
vector<vector<int>> adj;
int dfs(int here)
{
    if (fanclub[here])
        return 0;
    if (adj[here].empty())
        return 1;
    for (auto there : adj[here])
    {
        if (dfs(there))
            return 1;
    }
    return 0;
}
int main()
{
    fastio;
    cin >> n >> m;
    adj.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    cin >> s;
    for (int i = 0; i < s; i++)
    {
        int idx;
        cin >> idx;
        fanclub[idx] = true;
    }
    int ret = dfs(1);
    cout << (ret ? "yes" : "Yes");
    return 0;
}