#include <bits/stdc++.h>
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
using namespace std;
int n, m, p, q;
vector<vector<pair<int, int>>> adj;
vector<int> house, store;
int dist[5005];
const int inf = 987654321;
int dijkstra(vector<int> &h, vector<int> &s)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    fill(dist, dist + 5005, inf);

    for (auto ss : s)
    {
        pq.push({0, ss});
        dist[ss] = 0;
    }
    while (!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();
        int d = cur.first;
        int e = cur.second;
        if (d > dist[e])
            continue;
        for (auto nxt : adj[e])
        {
            int dx = nxt.first;
            int ne = nxt.second;
            if (dist[ne] > dx + d)
            {
                dist[ne] = dx + d;
                pq.push({dist[ne], ne});
            }
        }
    }
    vector<pair<int, int>> ans;
    for (auto hh : h)
    {
        ans.push_back({dist[hh], hh});
    }
    sort(ans.begin(), ans.end());
    return ans[0].second;
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
    cin >> p >> q;
    house.resize(p);
    store.resize(q);
    for (int i = 0; i < p; i++)
    {
        cin >> house[i];
    }
    for (int i = 0; i < q; i++)
    {
        cin >> store[i];
    }
    int answer = dijkstra(house, store);
    cout << answer;

    return 0;
}