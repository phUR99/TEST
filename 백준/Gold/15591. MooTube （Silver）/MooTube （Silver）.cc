#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n, q;
vector<vector<pair<int, int>>> adj;
bool visited[5005];
int dfs(int k, int here)
{
    visited[here] = 1;
    int ret = 1;
    for (auto nxt : adj[here])
    {
        int c = nxt.first;
        int there = nxt.second;
        if (visited[there])
            continue;
        if (c < k)
            continue;
        ret += dfs(k, there);
    }
    return ret;
}

void query(int USADO, int VIDEO)
{
    memset(visited, 0, sizeof(visited));
    int ret = dfs(USADO, VIDEO);
    cout << ret - 1 << '\n';
}

int main()
{
    fastio;
    cin >> n >> q;
    adj.resize(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }
    while (q--)
    {
        int k, c;
        cin >> k >> c;
        query(k, c);
    }

    return 0;
}