#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n, m, r;
int depth[100005];
vector<vector<int>> adj;

void bfs(int start)
{
    memset(depth, -1, sizeof(depth));
    depth[start] = 0;
    queue<int> q;
    q.push(start);
    while (!q.empty())
    {
        int here = q.front();
        q.pop();
        for (int there : adj[here])
        {
            if (depth[there] == -1)
            {
                depth[there] = depth[here] + 1;
                q.push(there);
            }
        }
    }
}

int main()
{
    fastio;
    cin >> n >> m >> r;
    adj.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bfs(r);
    for (int i = 1; i <= n; i++)
    {
        cout << depth[i] << '\n';
    }

    return 0;
}