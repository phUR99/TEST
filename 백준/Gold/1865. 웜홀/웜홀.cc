#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
vector<vector<pair<int, int>>> adj;
const int INF = 987654321;
vector<ll> upper;
bool bellmanFord(int src, int V)
{
    upper[src] = 0;
    bool updated;
    for (int iter = 0; iter < V; iter++)
    {
        updated = false;
        for (int here = 1; here <= V; here++)
        {
            for (auto nxt : adj[here])
            {
                int cost = nxt.first;
                int there = nxt.second;
                if (upper[here] + cost < upper[there])
                {
                    updated = true;
                    upper[there] = upper[here] + cost;
                }
            }
        }
        if (!updated)
            break;
    }
    if (updated)
        return true;
    return false;
}

void solve()
{
    int n, m, w;
    cin >> n >> m >> w;
    adj.clear();
    adj.resize(n + 1);
    upper.clear();
    upper.resize(n + 1, INF);
    for (int i = 0; i < m; i++)
    {
        int a, b, t;
        cin >> a >> b >> t;
        adj[b].push_back({t, a});
        adj[a].push_back({t, b});
    }
    for (int i = 0; i < w; i++)
    {
        int a, b, t;
        cin >> a >> b >> t;
        adj[a].push_back({-t, b});
    }
    for (int i = 1; i <= n; i++)
    {
        if (upper[i] == INF)
            if (bellmanFord(i, n))
            {
                cout << "YES\n";
                return;
            }
    }
    cout << "NO\n";
}

int main()
{
    fastio;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}