#include <bits/stdc++.h>
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
using namespace std;
vector<vector<int>> adj;
bool visited[100500];
int cache[100500][2];

void solve(int cur)
{
    visited[cur] = true;
    cache[cur][0] = 0;
    cache[cur][1] = 1;
    for (auto nxt : adj[cur])
    {
        if (visited[nxt])
            continue;
        solve(nxt);
        cache[cur][0] += cache[nxt][1];
        cache[cur][1] += min(cache[nxt][1], cache[nxt][0]);
    }
}

int main()
{
    fastio;
    int N;
    cin >> N;
    adj.resize(N + 1);
    for (int i = 0; i < N - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    solve(1);
    cout << min(cache[1][0], cache[1][1]);
    return 0;
}