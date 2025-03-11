#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int parent[100005];
int n, m;
int s, e;
vector<array<int, 3>> adj;
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

int solve()
{
    for (auto &i : adj)
    {
        if (!merge(i[1], i[2]))
            continue;
        if (find(s) == find(e))
            return i[0];
    }
    return 0;
}
int main()
{
    fastio;
    cin >> n >> m;
    cin >> s >> e;
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }
    adj.resize(m);
    for (auto &i : adj)
    {
        cin >> i[1] >> i[2] >> i[0];
    }
    sort(adj.begin(), adj.end(), greater<>());
    int ret = solve();

    cout << ret;
    return 0;
}