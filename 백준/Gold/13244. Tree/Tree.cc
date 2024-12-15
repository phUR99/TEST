#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int parent[1005];
int find(int u)
{
    if (parent[u] == u)
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
void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }
    vector<pair<int, int>> arr(m);
    for (auto &i : arr)
    {
        cin >> i.first >> i.second;
    }
    for (auto &i : arr)
    {
        int u = i.first;
        int v = i.second;
        if (!merge(u, v))
        {
            cout << "graph\n";
            return;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (find(i) != find(1))
        {
            cout << "graph\n";
            return;
        }
    }

    cout << "tree\n";
}
int main()
{
    fastio;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}