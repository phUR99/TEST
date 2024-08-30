#include <bits/stdc++.h>
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
using namespace std;
#define ll long long

ll dist[100005];
bool visited[100005];
const ll inf = 0x3fffffffffffffff;
ll n, m, c, sum, answer = 0x7fffffffffffffff;

vector<vector<pair<ll, int>>> adj;
void dijkstra()
{
    fill(dist, dist + n + 1, inf);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({0LL, 1});
    dist[1] = 0;
    while (!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();
        if (visited[cur.second])
            continue;
        if (cur.first > dist[cur.second])
            continue;
        visited[cur.second] = true;
        for (auto nxt : adj[cur.second])
        {
            if (visited[nxt.second])
                sum -= nxt.first;
        }
        answer = min(answer, c * cur.first + sum);
        for (auto nxt : adj[cur.second])
        {
            if (dist[nxt.second] > nxt.first + cur.first)
            {
                dist[nxt.second] = nxt.first + cur.first;
                pq.push({dist[nxt.second], nxt.second});
            }
        }
    }
}

int main()
{
    fastio;
    cin >> n >> m >> c;
    adj.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back({c, v});
        adj[v].push_back({c, u});
        sum += c;
    }
    dijkstra();
    cout << answer;
    return 0;
}