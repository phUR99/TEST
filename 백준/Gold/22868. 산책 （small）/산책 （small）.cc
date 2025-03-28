#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n, m;
vector<vector<int>> adj;
vector<int> visited;
vector<int> bfs(int s, int e){
    queue<int> q;
    vector<int> dist(n+1, -1);
    vector<int> trace(n+1, -1);
    dist[s] = 0;
    q.push(s);
    while (!q.empty())
    {
        int here = q.front(); q.pop();
        
        for (auto there: adj[here])
        {
            if (dist[there] == -1 && !visited[there]){
                dist[there] = dist[here] + 1;
                q.push(there);
                trace[there] = here;
            }
        }
        
    }
    return trace;
}

int main()
{
    fastio;
    cin >> n >> m;
    adj.resize(n+1);
    visited.resize(n+1, 0);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        sort(adj[i].begin(), adj[i].end());
    }
    int s, e;
    cin >> s >> e;
    int cnt = 0;
    vector<int> ret = bfs(s, e);
    for (int i = e; i != s; i = ret[i])
    {
        visited[i] = 1;
        cnt++;
    }
    ret = bfs(e, s);
    for (int i = s; i != e; i = ret[i])
    {
        cnt++;
    }
    cout << cnt;
    
    return 0;
}