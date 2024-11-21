#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
vector<vector<int>> adj;
int n;
vector<int> paths, curr;
int order[100005];
bool visited[100005];
bool cmp(const int a, const int b)
{
    return order[a] < order[b];
}

int main()
{
    fastio;
    cin >> n;
    adj.resize(n + 1);
    paths.resize(n);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i < n; i++)
    {
        cin >> paths[i];
        order[paths[i]] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        sort(adj[i].begin(), adj[i].end(), cmp);
    }
    queue<int> q;
    q.push(1);
    visited[1] = true;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        curr.push_back(cur);
        for (int nxt : adj[cur])
        {
            if (visited[nxt])
                continue;
            visited[nxt] = true;
            q.push(nxt);
        }
    }

    cout << (curr == paths);
    return 0;
}