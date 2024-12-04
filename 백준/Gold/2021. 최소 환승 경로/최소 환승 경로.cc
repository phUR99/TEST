#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n, l;
vector<vector<pair<int, int>>> adj;

int bfs(int s, int e)
{
    vector<int> dist(n + l + 1, -1);
    dist[s] = 0;
    deque<int> dq;
    dq.push_back(s);
    while (!dq.empty())
    {
        int here = dq.front();
        dq.pop_front();
        for (auto nxt : adj[here])
        {
            int cost = nxt.first;
            int there = nxt.second;
            if (dist[there] == -1)
            {
                if (cost)
                    dq.push_back(there);
                else
                    dq.push_front(there);
                dist[there] = dist[here] + cost;
            }
        }
    }
    if (dist[e] == -1)
        return -1;
    return dist[e] - 1;
}
int main()
{
    fastio;
    cin >> n >> l;
    adj.resize(n + l + 1);
    for (int i = 1; i <= l; i++)
    {
        int group = i + n;
        while (1)
        {
            int station;
            cin >> station;
            if (station == -1)
                break;
            adj[group].push_back({0, station});
            adj[station].push_back({1, group});
        }
    }
    int s, e;
    cin >> s >> e;
    int ret = bfs(s, e);
    if (s == e)
        ret = 0;
    cout << ret;
    return 0;
}