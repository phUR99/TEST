#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int parent[1000005];
int find(int u)
{
    if (u == parent[u])
        return u;
    return parent[u] = find(parent[u]);
}
void merge(int u, int v)
{
    u = find(u), v = find(v);
    if (u == v)
        return;
    parent[u] = v;
}
void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }
    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int u, v;
        cin >> u >> v;
        merge(u, v);
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        cout << (find(u) == find(v)) << '\n';
    }
    cout << '\n';
}

int main()
{
    fastio;
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cout << "Scenario " << i + 1 << ":\n";
        solve();
    }

    return 0;
}