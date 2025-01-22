#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n, m, t;
int parent[1005];
int find(int u)
{
    if (parent[u] == u)
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
int MST(deque<array<int, 3>> &arr)
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }

    int cnt = 0;
    int ret = 0;
    for (auto &i : arr)
    {
        int u = i[2];
        int v = i[1];
        int c = i[0];
        if (merge(u, v))
        {
            cnt++;
            ret += c;
        }
    }
    if (cnt != n - 1)
        ret = 0;
    return ret;
}

int main()
{
    fastio;
    cin >> n >> m >> t;
    deque<array<int, 3>> dq;
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        dq.push_back({i, a, b});
    }
    for (int i = 0; i < t; i++)
    {
        cout << MST(dq) << ' ';
        dq.pop_front();
    }

    return 0;
}