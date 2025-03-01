#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n, m;
vector<array<int, 3>> arr;
int parent[1005];
int find(int u)
{
    if (u == parent[u])
        return u;
    return parent[u] = find(parent[u]);
}
bool merge(int u, int v)
{
    u = find(u), v = find(v);
    if (u == v)
        return false;
    parent[u] = v;
    return true;
}
int main()
{
    fastio;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        merge(u, v);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int c;
            cin >> c;
            arr.push_back({c, i, j});
        }
    }
    sort(arr.begin(), arr.end());
    int ret = 0;
    vector<pair<int, int>> connect;
    for (auto a : arr)
    {
        int u = a[2];
        int v = a[1];
        int c = a[0];
        if (u == 1 || v == 1)
            continue;
        if (merge(u, v))
        {
            ret += c;
            connect.push_back({u, v});
        }
    }
    cout << ret << ' ' << connect.size() << '\n';
    for (auto t : connect)
    {
        cout << t.first << ' ' << t.second << '\n';
    }

    return 0;
}