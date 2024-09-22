#include <bits/stdc++.h>
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
using namespace std;
long long n, m;
long long dist[100005];
long long arr[100005];
vector<vector<pair<long, long long>>> adj;
const long long inf = (1LL << 63) - 1;

void dijkstra()
{
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
    pq.push({0, 0});
    dist[0] = 0;
    while (!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();
        long long d = cur.first;
        long long e = cur.second;
        if ((long long)d > dist[e])
            continue;
        for (auto nxt : adj[e])
        {
            long long nd = nxt.first;
            long long ne = nxt.second;
            if (arr[ne])
                continue;
            if (dist[ne] > (long long)nd + d)
            {
                dist[ne] = (long long)nd + d;
                pq.push({dist[ne], ne});
            }
        }
    }
}

int main()
{
    fastio;
    cin >> n >> m;
    fill(dist, dist + n, inf);
    adj.resize(n);
    for (long long i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    arr[n - 1] = 0;

    for (long long i = 0; i < m; i++)
    {
        long long a, b, t;
        cin >> a >> b >> t;
        adj[a].push_back({t, b});
        adj[b].push_back({t, a});
    }
    dijkstra();
    if (dist[n - 1] == inf)
        cout << -1;
    else
        cout << dist[n - 1];

    return 0;
}