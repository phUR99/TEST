#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int depth[100005];
bool visited[100005];
vector<vector<int>> adj;
int n, s, d;
int dfs(int here)
{
    int &ret = depth[here] = 0;
    for (int there : adj[here])
    {
        if (depth[there] == -1)
        {
            ret = max(ret, 1 + dfs(there));
        }
    }
    // cout << here << ' ' << ret << '\n';
    return ret;
}
int solve(int here)
{
    int ret = 0;
    visited[here] = 1;
    for (int there : adj[here])
    {
        if (visited[there])
            continue;
        if (depth[there] < d)
            continue;
        ret += 2 + solve(there);
    }
    return ret;
}

int main()
{
    fastio;

    memset(depth, -1, sizeof(depth));
    cin >> n >> s >> d;
    adj.resize(n + 1);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(s);
    int ret = solve(s);
    cout << ret;
    return 0;
}