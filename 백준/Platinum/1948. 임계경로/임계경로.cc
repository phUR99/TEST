#include <bits/stdc++.h>
using namespace std;
#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
int maxDist;
int S, E;
vector<vector<pair<int, int>>> adj, r_adj;
int dist[10005];
bool visited[10005];

void solve(int cur, int sum)
{

    if (cur == E)
    {
        return;
    }
    for (auto nxt : adj[cur])
    {
        if (nxt.first + sum > dist[nxt.second])
        {
            dist[nxt.second] = nxt.first + sum;
            solve(nxt.second, sum + nxt.first);
        }
    }
}

int n, m;

int main()
{
    fastio;
    cin >> n >> m;
    adj.resize(n + 1);
    r_adj.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        int s, e, c;
        cin >> s >> e >> c;
        adj[s].push_back({c, e});
        r_adj[e].push_back({c, s});
    }
    for (int i = 1; i <= n; i++)
    {
        sort(adj[i].begin(), adj[i].end(), greater<>());
    }

    cin >> S >> E;
    solve(S, 0);
    int ans = 0;
    visited[E] = true;
    queue<int> q;
    q.push(E);
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        for (auto nxt : r_adj[cur])
        {
            if (dist[cur] == dist[nxt.second] + nxt.first)
            {
                ans++;
                if (visited[nxt.second])
                    continue;
                visited[nxt.second] = true;
                q.push(nxt.second);
            }
        }
    }

    cout << dist[E] << '\n';
    cout << ans;

    return 0;
}