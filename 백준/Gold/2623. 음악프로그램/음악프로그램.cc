#include <bits/stdc++.h>

using namespace std;
#define ll long long

int deg[1005];
vector<int> adj[1005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    while (m--)
    {
        int u, v, k;
        cin >> k >> u;
        k--;
        while (k--)
        {
            cin >> v;
            adj[u].push_back(v);
            deg[v]++;
            u = v;
        }
    }
    queue<int> q;
    vector<int> res;
    for (int i = 1; i <= n; i++)
    {
        if (deg[i] == 0) q.push(i);
    }
    while (!q.empty())
    {
        int cur = q.front(); q.pop();
        res.push_back(cur);
        for (int nxt : adj[cur])
        {
            deg[nxt]--;
            if (deg[nxt] == 0) q.push(nxt);
        }
    }
    if (res.size() != n)
    {
        cout << 0;
        return 0;
    }
    for (auto e : res) {
        cout << e << '\n';
    }
}