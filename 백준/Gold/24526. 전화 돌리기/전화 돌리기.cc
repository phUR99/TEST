#include <bits/stdc++.h>
using namespace std;
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
int cache[100005];
bool visited[100005];
int dfs(int cur, vector<vector<int>> &adj)
{

    int &ret = cache[cur];
    if (ret != -1)
        return ret;
    ret = 1;
    for (auto nxt : adj[cur])
    {
        if (visited[nxt])
            return ret = 0;

        visited[nxt] = true;
        ret &= dfs(nxt, adj);
        visited[nxt] = false;
    }
    return ret;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    memset(cache, -1, sizeof(cache));
    int answer = 0;
    for (int i = 1; i <= n; i++)
    {
        visited[i] = true;
        answer += dfs(i, adj);
        visited[i] = false;
    }
    cout << answer << '\n';
}

int main()
{
    fastio;
    solve();

    return 0;
}
