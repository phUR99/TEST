#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int v, e, p;
vector<vector<pair<int, int>>> adj;
int dijkstra(int st, int ed)
{
    priority_queue<pair<int, int>> pq;
    pq.push({0, st});
    vector<int> dist(v + 1, 987654321);
    dist[st] = 0;
    while (!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();
        int here = cur.second;
        int d = -cur.first;
        if (dist[here] < d)
            continue;
        for (auto nxt : adj[here])
        {
            int there = nxt.second;
            int w = nxt.first;
            if (dist[there] > w + d)
            {
                dist[there] = w + d;
                pq.push({-dist[there], there});
            }
        }
    }
    return dist[ed];
}

int main()
{
    fastio;
    cin >> v >> e >> p;
    adj.resize(v + 1);
    for (int i = 0; i < e; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }
    int total = dijkstra(1, v);
    int d1 = dijkstra(p, 1);
    int d2 = dijkstra(p, v);
    if (d1 + d2 == total)
        cout << "SAVE HIM";
    else
        cout << "GOOD BYE";
    return 0;
}