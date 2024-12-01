#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
vector<vector<int>> adj;
int n;

bool visited[3005];
bool isCycle[3005];
int dist[3005];

bool dfs(int here, int prev, int start)
{
    visited[here] = true;
    for (int there : adj[here])
    {
        if (there == prev)
            continue;
        if (there == start)
            return isCycle[here] = true;
        if (!visited[there])
        {
            isCycle[here] |= dfs(there, here, start);
        }
    }
    return isCycle[here];
}

int main()
{
    fastio;
    cin >> n;
    adj.resize(n + 1);
    memset(dist, -1, sizeof(dist));
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 1; i <= n; i++)
    {
        memset(visited, 0, sizeof(visited));
        if (dfs(i, -1, i))
            break;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (isCycle[i])
        {
            q.push(i);
            dist[i] = 0;
        }
    }
    while (!q.empty())
    {
        int here = q.front();
        q.pop();
        for (int there : adj[here])
        {
            if (dist[there] == -1)
            {
                dist[there] = dist[here] + 1;
                q.push(there);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << dist[i] << ' ';
    }

    return 0;
}