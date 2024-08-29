#include <bits/stdc++.h>
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
using namespace std;
int n, m;
vector<vector<pair<int, int>>> adj;
int cache[1005];
int solve(int cur)
{
    if (cur == n + 1)
        return cache[cur] = 0;
    int &ret = cache[cur];
    if (ret != -1)
        return ret;
    ret = 0;
    for (auto nxt : adj[cur])
    {
        ret = max(ret, nxt.first + solve(nxt.second));
    }
    return ret;
}
void trace(int cur)
{

    if (cur == n + 1)
    {
        cout << 1;
        return;
    }
    cout << cur << ' ';

    for (auto nxt : adj[cur])
    {
        if (cache[cur] == nxt.first + cache[nxt.second])
            trace(nxt.second);
    }
}

int main()
{
    fastio;
    cin >> n >> m;
    adj.resize(n + 2);
    memset(cache, -1, sizeof(cache));

    for (int i = 0; i < m; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        if (v == 1)
            v = n + 1;
        adj[u].push_back({c, v});
    }
    cout << solve(1) << '\n';
    trace(1);
    return 0;
}