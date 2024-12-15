#include <bits/stdc++.h>
using namespace std;
#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0)
#define ll long long

int N, M;
vector<pair<int, int>> adj[200005];
int dist[200005];
bool del[200005];
int A, B;

void trace(int here)
{
    if (here == B)
        return;
    for (auto nxt : adj[here])
    {
        int there = nxt.first;
        int cost = nxt.second;
        if (dist[here] == dist[there] + cost)
        {
            del[there] = true;
            trace(there);
            return;
        }
    }
}

int dijkstra(int s, int e)
{
    memset(dist, 0x3f, sizeof(dist));
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});
    dist[s] = 0;
    while (!pq.empty())
    {

        auto cur = pq.top();
        pq.pop();
        if (cur.first > dist[cur.second])
            continue;
        for (auto nxt : adj[cur.second])
        {
            if (nxt.second + cur.first < dist[nxt.first] && !del[nxt.first])
            {
                dist[nxt.first] = nxt.second + cur.first;
                pq.push({dist[nxt.first], nxt.first});
            }
        }
    }
    return dist[e];
}

int main()
{
    fastio;
    cin >> N >> M;
    int u, v, c;

    for (int i = 0; i < M; i++)
    {
        cin >> u >> v >> c;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }
    cin >> A >> B;
    for (int i = 1; i <= N; i++)
    {
        sort(adj[i].begin(), adj[i].end());
    }
    int e2s = dijkstra(B, A);
    trace(A);
    del[B] = 0;
    /*
    for (int i = 1; i <= N; i++)
    {
        cout << "i: " << i << ' ' << del[i] << '\n';
    }
    */
    int s2e = dijkstra(A, B);
    cout << s2e + e2s;
    return 0;
}