#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
vector<vector<pair<int, int>>> adj;
int dist[1005];

void solve()
{
    int v, e, n, m;
    adj.clear();

    cin >> v >> e >> n >> m;
    adj.resize(v + 1);
    memset(dist, 0x3f, sizeof(dist));
    for (int i = 0; i < e; i++)
    {
        int a, b, t;
        cin >> a >> b >> t;
        adj[a].push_back({t, b});
        adj[b].push_back({t, a});
    }
    priority_queue<pair<int, int>> pq;
    vector<int> fire(n);
    for (int i = 0; i < n; i++)
    {
        cin >> fire[i];
    }
    for (int i = 0; i < m; i++)
    {
        int fireStation;
        cin >> fireStation;
        pq.push({0, fireStation});
        dist[fireStation] = 0;
    }
    while (!pq.empty())
    {
        auto tmp = pq.top();
        pq.pop();
        int here = tmp.second;
        int cost = -tmp.first;
        if (dist[here] < cost)
            continue;
        for (auto nxt : adj[here])
        {
            int there = nxt.second;
            int nCost = nxt.first;
            if (nCost + cost < dist[there])
            {
                dist[there] = nCost + cost;
                pq.push({-dist[there], there});
            }
        }
    }
    int answer = 0;
    for (auto i : fire)
    {
        answer += dist[i];
    }
    cout << answer << '\n';
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