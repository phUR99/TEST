#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n, m;
int parent[200005];
int find(int u)
{
    if (u == parent[u])
        return u;
    return parent[u] = find(parent[u]);
}
bool merge(int u, int v)
{
    u = find(u);
    v = find(v);
    if (u == v)
        return false;
    parent[u] = v;
    return true;
}

int MST(vector<vector<int>> &adj)
{
    int ret = 0;
    for (auto &v : adj)
    {
        int x = v[1];
        int y = v[2];
        int c = v[0];
        if (merge(x, y))
            ret += c;
    }
    return ret;
}

int main()
{
    fastio;
    vector<vector<int>> adj;
    cin >> n >> m;
    adj.resize(m, vector<int>(3));
    for (int i = 1; i <= n + 1; i++)
    {
        parent[i] = i;
    }

    for (int i = 0; i < m; i++)
    {
        cin >> adj[i][1] >> adj[i][2] >> adj[i][0];
    }
    for (int i = 1; i <= n; i++)
    {
        vector<int> tmp(3);
        tmp[1] = i;
        tmp[2] = n + 1;
        cin >> tmp[0];
        adj.push_back(tmp);
    }
    sort(adj.begin(), adj.end());
    int ret = MST(adj);
    cout << ret << '\n';
    return 0;
}