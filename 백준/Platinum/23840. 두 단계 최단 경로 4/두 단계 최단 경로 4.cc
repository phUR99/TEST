#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n, m, st, ed, p;
vector<vector<pair<int, int>>> adj;
ll trans[22][22];
map<int, int> compress_ID;
ll cache[1 << 22][22];

void dijkstra(int st)
{
    vector<ll> dist(n + 1, 1e12);
    priority_queue<pair<ll, int>> pq;
    dist[st] = 0;
    pq.push({0, st});
    while (!pq.empty())
    {
        auto current = pq.top();
        pq.pop();
        ll cost = -current.first;
        int here = current.second;
        if (dist[here] < cost)
            continue;
        for (auto &nxt : adj[here])
        {
            int nCost = nxt.first;
            int there = nxt.second;
            if (cost + (ll)nCost < dist[there])
            {
                dist[there] = cost + (ll)nCost;
                pq.push({-dist[there], there});
            }
        }
    }
    for (auto &vertex : compress_ID)
    {
        if (vertex.first == st)
            continue;
        trans[compress_ID[st]][vertex.second] = dist[vertex.first];
    }
}
ll solve(int state, int here)
{
    if (state == (1 << (p + 2)) - 1)
    {
        if (here == compress_ID[ed])
            return 0;
        return 1e12;
    }
    ll &ret = cache[state][here];
    if (ret != -1)
        return ret;
    ret = 1e12;
    for (int i = 0; i < p + 2; i++)
    {
        if (state & (1 << i))
            continue;
        if (trans[here][i] == 1e12)
            continue;
        int nxtState = state | (1 << i);
        ret = min(ret, trans[here][i] + solve(nxtState, i));
    }
    return ret;
}

int main()
{
    fastio;
    memset(cache, -1, sizeof(cache));
    cin >> n >> m;
    adj.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }
    cin >> st >> ed;
    cin >> p;
    for (int i = 0; i < p + 2; i++)
    {
        for (int j = 0; j < p + 2; j++)
        {
            trans[i][j] = 1e12;
        }
    }

    for (int i = 0; i < p; i++)
    {
        int vertex;
        cin >> vertex;
        compress_ID[vertex] = i;
    }
    compress_ID[st] = p;
    compress_ID[ed] = p + 1;

    for (auto &v : compress_ID)
    {
        dijkstra(v.first);
    }
    ll ret = solve(1 << (compress_ID[st]), compress_ID[st]);
    if (ret == 1e12)
        ret = -1;
    cout << ret;
    return 0;
}