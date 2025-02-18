#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n, m;
vector<vector<int>> adj;
int s[100005], e[100005];
int tree[400005];
int cnt;
void dfs(int here, int parent)
{
    s[here] = ++cnt;
    for (int there : adj[here])
    {
        if (there == parent)
            continue;
        dfs(there, here);
    }
    e[here] = cnt;
}
void update(int l, int r, int node, int t, int w)
{
    if (l > t || t > r)
        return;
    tree[node] += w;
    if (l == r)
        return;
    int m = (l + r) / 2;
    update(l, m, node * 2, t, w);
    update(m + 1, r, node * 2 + 1, t, w);
}
int query(int l, int r, int n, int ql, int qr)
{
    if (qr < l || ql > r)
        return 0;
    if (l >= ql && r <= qr)
        return tree[n];
    int m = (l + r) / 2;
    return query(l, m, n * 2, ql, qr) + query(m + 1, r, n * 2 + 1, ql, qr);
}

int main()
{
    fastio;
    cin >> n >> m;
    adj.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int v;
        cin >> v;
        if (v == -1)
            continue;
        adj[i].push_back(v);
        adj[v].push_back(i);
    }
    dfs(1, -1);
    for (int i = 0; i < m; i++)
    {
        int cmd;
        cin >> cmd;
        if (cmd == 1)
        {
            int u, w;
            cin >> u >> w;
            update(1, n, 1, s[u], w);
        }
        else
        {
            int u;
            cin >> u;
            cout << query(1, n, 1, s[u], e[u]) << '\n';
        }
    }

    return 0;
}