#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n, m, k, x;
vector<int> solve(vector<vector<int>> &adj)
{
    vector<int> dist(n + 1, -1);
    dist[x] = 0;
    queue<int> q;
    q.push(x);
    while (!q.empty())
    {
        int here = q.front();
        q.pop();
        for (int there : adj[here])
        {
            if (dist[there] != -1)
                continue;
            dist[there] = dist[here] + 1;
            q.push(there);
        }
    }
    return dist;
}

int main()
{
    fastio;
    cin >> n >> m >> k >> x;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    vector<int> ret = solve(adj);
    int answer = 0;
    for (auto &i : ret)
    {
        answer += (i == k);
    }
    if (answer == 0)
    {
        cout << -1;
        return 0;
    }
    for (int i = 1; i <= n; i++)
    {
        if (ret[i] == k)
            cout << i << '\n';
    }

    return 0;
}