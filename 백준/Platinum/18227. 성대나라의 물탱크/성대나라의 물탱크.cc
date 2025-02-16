#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n, c, q;
vector<vector<int>> adj;
int s[200005];
int e[200005];
int tree[800005];
int cnt;
int depth[200005];
void dfs(int here, int parent, int h)
{
    s[here] = ++cnt;
    depth[here] = h;
    for (int there : adj[here])
    {
        if (there == parent)
            continue;
        dfs(there, here, h + 1);
    }
    e[here] = cnt;
}
void update(int left, int right, int node, int target)
{
    if (left > target || right < target)
        return;
    tree[node]++;
    if (left == right)
        return;
    int mid = (left + right) / 2;

    update(left, mid, node * 2, target);
    update(mid + 1, right, node * 2 + 1, target);
}
int query(int left, int right, int node, int qleft, int qright)
{
    if (left > qright || right < qleft)
        return 0;
    if (left >= qleft && right <= qright)
        return tree[node];
    int mid = (left + right) / 2;
    return query(left, mid, node * 2, qleft, qright) + query(mid + 1, right, node * 2 + 1, qleft, qright);
}

int main()
{
    fastio;
    cin >> n >> c;
    adj.resize(n + 1);

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(c, -1, 1);
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int cmd, a;
        cin >> cmd >> a;
        if (cmd == 1)
        {
            int l = s[a];
            update(1, n, 1, l);
        }
        else
        {
            int l = s[a];
            int r = e[a];
            cout << 1LL * query(1, n, 1, l, r) * depth[a] << '\n';
        }
    }
    return 0;
}