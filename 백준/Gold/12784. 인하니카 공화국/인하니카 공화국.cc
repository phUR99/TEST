#include <bits/stdc++.h>
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
using namespace std;
int T, N, M;
vector<vector<pair<int, int>>> adj;
int cache[1005];
bool visited[1005];
int solve(int cur)
{
    visited[cur] = true;
    bool isLeaf = true;
    int ret = 0;

    for (auto nxt : adj[cur])
    {
        if (visited[nxt.second])
            continue;
        isLeaf = false;
        ret += min(nxt.first, solve(nxt.second));
    }
    if (isLeaf)
        return 987654321;
    return ret;
}

int main()
{
    fastio;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        cin >> N >> M;
        adj.clear();
        adj.resize(N + 1);
        memset(cache, -1, sizeof(cache));
        memset(visited, false, sizeof(visited));

        for (int i = 0; i < M; i++)
        {
            int u, v, c;
            cin >> u >> v >> c;
            adj[u].push_back({c, v});
            adj[v].push_back({c, u});
        }
        if (N == 1)
            cout << 0;
        else
            cout << solve(1) << '\n';
    }

    return 0;
}