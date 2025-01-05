#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n, m;
vector<vector<pair<int, int>>> adj;
int dist[1005];
int cache[1005];

void dijkstra(int s)
{
    memset(dist, 0x3f, sizeof(dist));
    priority_queue<pair<int, int>> pq;
    pq.push({0, 2});
    dist[2] = 0;
    while (!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();
        int cost = -cur.first;
        int here = cur.second;
        if (cost > dist[here])
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
            if (dist[here] > dist[there])
            {
                cache[here] += cache[there];
            }
        }
    }
}

int main()
{
    fastio;
    cin >> n >> m;
    adj.resize(n + 1);
    cache[2] = 1;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }
    dijkstra(2);
    cout << cache[1];
    return 0;
}