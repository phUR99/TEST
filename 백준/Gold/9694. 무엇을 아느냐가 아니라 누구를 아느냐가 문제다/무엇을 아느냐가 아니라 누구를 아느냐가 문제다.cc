#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
vector<vector<pair<int, int>>> adj;

vector<int> dijkstra(int st, int ed)
{
    vector<int> dist(adj.size(), 1e9);
    dist[st] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({0, st});
    while (!pq.empty())
    {
        auto here = pq.top();
        pq.pop();
        int hereCost = -here.first;
        int hereNode = here.second;
        if (dist[hereNode] < hereCost)
            continue;
        for (auto there : adj[hereNode])
        {
            int thereCost = hereCost + there.first;
            int thereNode = there.second;
            if (dist[thereNode] > thereCost)
            {
                dist[thereNode] = thereCost;
                pq.push({-thereCost, thereNode});
            }
        }
    }
    if (dist[ed] == 1e9)
        return vector<int>();
    vector<int> ret;
    for (int here = ed; here != 0;)
    {
        ret.push_back(here);
        for (auto there : adj[here])
        {
            int thereCost = dist[there.second] + there.first;
            if (dist[here] == thereCost)
            {
                here = there.second;
                break;
            }
        }
    }
    return ret;
}

void solve(int t)
{
    int n, m;
    cin >> n >> m;
    adj.clear();
    adj.resize(m);
    for (int i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }
    vector<int> ret = dijkstra(0, m - 1);
    cout << "Case #" << t << ": ";
    if (ret.empty())
        cout << -1 << '\n';
    else
    {
        ret.push_back(0);
        reverse(ret.begin(), ret.end());
        for (auto i : ret)
        {
            cout << i << ' ';
        }
    }
    cout << '\n';
}

int main()
{
    fastio;
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        solve(i);
    }

    return 0;
}