#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n, m;
vector<vector<pair<int, int>>> adj;
int dijkstra(int st, int ed)
{
    vector<int> dist(n + 1, 1e9);
    dist[st] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({0, st});
    while (!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();
        int cost = -cur.first;
        int here = cur.second;
        if (cost < dist[here])
            continue;
        for (auto nxt : adj[here])
        {
            int w = nxt.first;
            int there = nxt.second;
            if (w + cost < dist[there])
            {
                dist[there] = w + cost;
                pq.push({-dist[there], there});
            }
        }
    }
    return dist[ed];
}

int main()
{
    fastio;
    cin >> n >> m;
    adj.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }
    int s, e;
    cin >> s >> e;
    int ret = dijkstra(s, e);
    cout << ret;
    return 0;
}