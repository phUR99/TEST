#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int parent[3005];
int x[3005], y[3005], r[3005];
int find(int u)
{
    if (parent[u] == u)
        return u;
    return parent[u] = find(parent[u]);
}
int square(int x)
{
    return x * x;
}
int dist(int x1, int y1, int x2, int y2)
{
    return square(x1 - x2) + square(y1 - y2);
}

bool merge(int u, int v)
{
    bool isInside = (dist(x[u], y[u], x[v], y[v]) <= dist(r[u], 0, -r[v], 0));
    if (!isInside)
        return false;
    u = find(u);
    v = find(v);
    if (u == v)
        return false;
    parent[u] = v;
    return true;
}

void solve()
{
    int n;
    cin >> n;
    int ret = n;
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i] >> r[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (merge(i, j))
                ret--;
        }
    }
    cout << ret << '\n';
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