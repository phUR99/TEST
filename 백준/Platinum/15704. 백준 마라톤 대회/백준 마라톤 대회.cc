#include <bits/stdc++.h>
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
using namespace std;
#define ll long long
ll dist[100005];
bool visited[100005];

vector<vector<vector<int>>> adj;
int n, m;
ll k;

bool solve(ll x)
{
    fill(dist, dist + n + 1, 0x7fffffffffffffff);
    memset(visited, 0, sizeof(visited));
    dist[1] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({0, 1});
    while (!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();
        if (cur.first > dist[cur.second])
            continue;
        if (visited[cur.second] || dist[cur.second] > k)
            break;
        visited[cur.second] = true;
        for (auto nxt : adj[cur.second])
        {
            int pos = nxt[0];
            ll cost = max(0LL, -(ll)nxt[2] + x) * max(0LL, -(ll)nxt[2] + x) * nxt[1];
            if (cost > k || max(0LL, -(ll)nxt[2] + x) * nxt[1] > k)
                continue;

            if (dist[pos] > cur.first + cost)
            {
                dist[pos] = cur.first + cost;
                pq.push({dist[pos], pos});
            }
        }
    }
    return dist[n] <= k;
}

int main()
{
    fastio;
    cin >> n >> m >> k;
    adj.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v, c, t;
        cin >> u >> v >> c >> t;
        adj[u].push_back({v, c, t});
        adj[v].push_back({u, c, t});
    }
    ll l = 1;
    ll r = 1'000'000'000;
    while (l <= r)
    {
        ll mid = (l + r) / 2;
        if (solve(mid))
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    cout << r;
    return 0;
}