#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n;
vector<vector<pair<int, int>>> adj;
vector<int> dijkstra(int st)
{
    priority_queue<pair<int, int>> pq;
    vector<int> dist(n + 1, 1987654321);
    dist[st] = 0;
    pq.push({0, st});
    while (!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();
        int d = -cur.first;
        int here = cur.second;
        if (d > dist[here])
            continue;
        for (auto &nxt : adj[here])
        {
            int w = nxt.first;
            int there = nxt.second;
            if (dist[there] > w + d)
            {
                dist[there] = w + d;
                pq.push({-dist[there], there});
            }
        }
    }
    return dist;
}
int main()
{
    fastio;
    cin >> n;
    adj.reserve(n + 1);
    int a, b, c;
    cin >> a >> b >> c;
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }
    vector<int> A = dijkstra(a);
    vector<int> B = dijkstra(b);
    vector<int> C = dijkstra(c);
    int idx = -1;
    int val = -1;
    for (int i = 1; i < n + 1; i++)
    {
        int v = min({A[i], B[i], C[i]});
        if (v > val)
        {
            idx = i;
            val = v;
        }
    }
    cout << idx;
    return 0;
}