#include <bits/stdc++.h>

using namespace std;
#define ll long long

int deg[32'005];
vector<int> vertex[32'005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        vertex[u].push_back(v);
        deg[v]++;
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
        for (int nxt : vertex[cur])
        {
            deg[nxt]--;
            if (deg[nxt] == 0) q.push(nxt);
            
        }
    }
    for (auto e : res )
    {
        cout << e << ' ';
    }
}