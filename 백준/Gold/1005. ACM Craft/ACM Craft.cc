#include <bits/stdc++.h>

using namespace std;
#define ll long long

int solve() {
    int n, k; cin >> n >> k;

    vector<int> adj[1005];
    int cost[1005] = {};
    int tot[1005] = {};
    int idx[1005] = {};

    for (int i = 1; i <= n; i++)
    {
        cin >> cost[i];
    }
    
    while (k--)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        idx[v]++;
    }
    int g; cin >> g;
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (idx[i] == 0) q.push(i);
    }
    while (!q.empty())
    {
        int cur = q.front(); q.pop();
        for (int nxt : adj[cur])
        {
            tot[nxt] = max(tot[nxt], cost[cur] + tot[cur]);
            idx[nxt]--;
            if (idx[nxt] == 0) q.push(nxt);
        }
    }
    return tot[g] + cost[g];

    
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cout << solve() << '\n';
    }
}
