#include <bits/stdc++.h>
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
using namespace std;
int dist_j[105];
int dist_s[105];
int v, m;
int j, s;
vector<vector<pair<int, int>>> adj;

void dijkstra(int st, int dist[])
{
    dist[st] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, st});
    while (!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();
        int distance = cur.first;
        int edge = cur.second;
        if (distance > dist[edge])
            continue;
        for (auto nxt : adj[edge])
        {
            int nxtEdge = nxt.second;
            int nxtWeight = nxt.first;
            if (dist[nxtEdge] > nxtWeight + distance)
            {
                dist[nxtEdge] = nxtWeight + distance;
                pq.push({dist[nxtEdge], nxtEdge});
            }
        }
    }
}

int main()
{
    fastio;
    fill(dist_j, dist_j + 105, 987654321);
    fill(dist_s, dist_s + 105, 987654321);
    cin >> v >> m;
    adj.resize(v + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }
    cin >> j >> s;
    dijkstra(j, dist_j);
    dijkstra(s, dist_s);
    vector<vector<int>> answer;
    int value = 987654321;
    for (int i = 1; i <= v; i++)
    {
        if (i == j || i == s)
            continue;
        if (dist_j[i] == 987654321 || dist_s[i] == 987654321)
            continue;
        value = min(value, dist_j[i] + dist_s[i]);
    }
    for (int i = 1; i <= v; i++)
    {
        if (i == j || i == s)
            continue;
        if (dist_j[i] == 987654321 || dist_s[i] == 987654321)
            continue;
        if (dist_j[i] + dist_s[i] != value)
            continue;
        if (dist_j[i] > dist_s[i])
            continue;
        answer.push_back({dist_j[i] + dist_s[i], dist_j[i], i});
    }
    sort(answer.begin(), answer.end());
    if (answer.empty())
        cout << -1;
    else
        cout << answer[0][2];
    return 0;
}