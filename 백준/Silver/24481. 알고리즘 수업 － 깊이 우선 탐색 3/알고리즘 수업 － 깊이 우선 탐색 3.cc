#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n, m, r;
int depth[100005];
vector<vector<int>> adj;
void dfs(int here)
{
    for (int there : adj[here])
    {
        if (depth[there] == -1)
        {
            depth[there] = depth[here] + 1;
            dfs(there);
        }
    }
}

int main()
{
    fastio;
    cin >> n >> m >> r;
    adj.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 1; i <= n; i++)
    {
        sort(adj[i].begin(), adj[i].end());
    }
    memset(depth, -1, sizeof(depth));
    depth[r] = 0;
    dfs(r);
    for (int i = 1; i <= n; i++)
    {
        cout << depth[i] << '\n';
    }

    return 0;
}